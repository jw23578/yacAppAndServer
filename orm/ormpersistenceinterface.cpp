#include "ormpersistenceinterface.h"
#include "utils/extuuid.h"
#include "orm_implementions/t0035_blobs.h"

ORMPersistenceInterface::ORMPersistenceInterface(ORMSqlInterface &sqlInterface):sqlInterface(sqlInterface) {}

bool ORMPersistenceInterface::insertObject(const ORMObjectInterface &object) const
{
    SqlString sql;
    sql.insert(MACRO_ORM_STRING_2_STD_STRING(object.getORMName()));
    for (const auto &p: object.getProperties())
    {
        if (p->hasDetail(DetailDB))
        {
            sql.addInsert(MACRO_ORM_STRING_2_STD_STRING(p->name()), p->asString(), p->isNull());
        }
    }
    return sqlInterface.execute(sql);
}

bool ORMPersistenceInterface::selectObject(const ORMUuid &id, ORMObjectInterface &target)
{
    SqlString sql;
    sql.select(MACRO_ORM_STRING_2_STD_STRING(target.getORMName()));
    sql.addCompare("where", MACRO_ORM_STRING_2_STD_STRING(tableFields.id), "=", MACRO_ORM_STRING_2_STD_STRING(id));
    if (!sqlInterface.open(sql))
    {
        return false;
    }
    target.fill(sqlInterface);
    return true;
}

bool ORMPersistenceInterface::updateObject(const ORMObjectInterface &object)
{
    SqlString sql;
    sql.update(MACRO_ORM_STRING_2_STD_STRING(object.getORMName()));
    for (const auto &p: object.getProperties())
    {
        if (p->hasDetail(DetailDB))
        {
            sql.addSet(MACRO_ORM_STRING_2_STD_STRING(p->name()), p->asString(), p->isNull());
        }
    }
    sql.addCompare("where", MACRO_ORM_STRING_2_STD_STRING(tableFields.id), "=", MACRO_ORM_STRING_2_STD_STRING(object.getPropertyToString(tableFields.id)));
    return sqlInterface.execute(sql);
}

bool ORMPersistenceInterface::upsertObject(ORMObjectInterface &object)
{
    if (object.propertyIsNull(tableFields.id))
    {
        object.setUuid(tableFields.id, ExtUuid::generateUuid());
        return insertObject(object);
    }
    return updateObject(object);
}

bool ORMPersistenceInterface::deleteObject(ORMObjectInterface &object)
{
    SqlString sql;
    sql.delet(MACRO_ORM_STRING_2_STD_STRING(object.getORMName()));
    sql.addCompare("where", MACRO_ORM_STRING_2_STD_STRING(tableFields.id), "=", MACRO_ORM_STRING_2_STD_STRING(object.getPropertyToString(tableFields.id)));
    return sqlInterface.execute(sql);
}

bool ORMPersistenceInterface::sameDataExists(ORMObjectInterface &object) const
{
    SqlString sql("select id from ");
    sql += MACRO_ORM_STRING_2_STD_STRING(object.getORMName());

    bool firstCompare(true);
    for (const auto &p: object.getProperties())
    {
        if (p->hasDetail(DetailDB) && !p->hasDetail(DetailID))
        {
            sql.addCompare(firstCompare ? "where" : "and", MACRO_ORM_STRING_2_STD_STRING(p->name()), "=", MACRO_ORM_STRING_2_STD_STRING(p->asString()));
            firstCompare = false;
        }
    }
    sql += " limit 1";
    sqlInterface.open(sql);
    if (sqlInterface.size() > 0)
    {
        object.setUuid("id", sqlInterface.uuidValue("id").value());
        return true;
    }
    return false;
}

bool ORMPersistenceInterface::insertIfNotSameDataExists(ORMObjectInterface &object) const
{
    if (sameDataExists(object))
    {
        return true;
    }
    return insertObject(object);
}

size_t ORMPersistenceInterface::fetchIDs(const SqlString &sql,
                                         std::set<ORMUuid> &ids)
{
    if (!sqlInterface.open(sql))
    {
        return 0;
    }
    for (size_t i(0); i < sqlInterface.size(); ++i)
    {
        std::string s(sqlInterface.value("id").value_or(""));
        if (s.size())
        {
            ids.insert(ExtUuid::stringToUuid(MACRO_STD_STRING_2_ORM_STRING(s)));
        }
        sqlInterface.next();
    }
    return ids.size();
}

ORMUuid ORMPersistenceInterface::storeBlob(const std::basic_string<std::byte> &data)
{
    t0035_blobs t0035;
    t0035.setid(ExtUuid::generateUuid());
    t0035.setblob_oid(sqlInterface.storeBlob(data));
    insertObject(t0035);
    return t0035.getid();
}

bool ORMPersistenceInterface::fetchBlob(const ORMUuid &blobUuid, std::basic_string<std::byte> &data)
{
    t0035_blobs t0035;
    if (!selectObject(blobUuid, t0035))
    {
        return false;
    }
    return sqlInterface.fetchBlob(t0035.getblob_oid(), data);
}

bool ORMPersistenceInterface::deleteBlob(const ORMUuid &blobUuid)
{
    t0035_blobs t0035;
    if (!selectObject(blobUuid, t0035))
    {
        return false;
    }
    deleteObject(t0035);
    return true;

}
