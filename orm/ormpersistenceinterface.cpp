#include "ormpersistenceinterface.h"
#include "utils/extuuid.h"
#include "orm_implementions/t0035_blobs.h"

ORMPersistenceInterface::ORMPersistenceInterface(ORMSqlInterface &sqlInterface):sqlInterface(sqlInterface) {}

bool ORMPersistenceInterface::insertObject(const ORMObjectInterface &object) const
{
    SqlString sql;
    sql.insert(object.getORMName());
    const std::set<ORMString> &propertyNames(object.propertyNames());
    for (auto &n: propertyNames)
    {
        ORMPropertyInterface *pi(object.getProperty(n));
        if (pi->hasDetail(DetailDB))
        {
            sql.addInsert(n, pi->asString(), pi->isNull());
        }
    }
    return sqlInterface.execute(sql);
}

bool ORMPersistenceInterface::selectObject(const ORMUuid &id, ORMObjectInterface &target)
{
    SqlString sql;
    sql.select(target.getORMName());
    sql.addCompare("where", tableFields.id, "=", id);
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
    sql.update(object.getORMName());
    const std::set<ORMString> &propertyNames(object.propertyNames());
    for (auto &n: propertyNames)
    {
        ORMPropertyInterface *pi(object.getProperty(n));
        if (pi->hasDetail(DetailDB) && !pi->hasDetail(DetailID))
        {
            sql.addSet(n, pi->asString(), pi->isNull());
        }
    }
    sql.addCompare("where", tableFields.id, "=", object.getPropertyToString(tableFields.id));
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
    sql.delet(object.getORMName());
    sql.addCompare("where", tableFields.id, "=", object.getPropertyToString(tableFields.id));
    return sqlInterface.execute(sql);
}

bool ORMPersistenceInterface::sameDataExists(ORMObjectInterface &object) const
{
    SqlString sql("select id from ");
    sql += object.getORMName();
    const std::set<ORMString> &propertyNames(object.propertyNames());
    bool firstCompare(true);
    for (auto &n: propertyNames)
    {
        ORMPropertyInterface *pi(object.getProperty(n));
        if (pi->hasDetail(DetailDB) && !pi->hasDetail(DetailID))
        {
            if (firstCompare)
            {
                sql.addCompare(firstCompare ? "where" : "and", n, "=", pi->asString());
                firstCompare = false;
            }
        }
    }
    sql += " limit 1";
    sqlInterface.execute(sql);
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
            ids.insert(ExtUuid::stringToUuid(s));
        }
        sqlInterface.next();
    }
    return ids.size();
}

ORMUuid ORMPersistenceInterface::storeBlob(const std::basic_string<std::byte> &data)
{
    t0035_blobs t0035;
    t0035.id = ExtUuid::generateUuid();
    t0035.blob_oid = sqlInterface.storeBlob(data);
    insertObject(t0035);
    return t0035.id;
}

bool ORMPersistenceInterface::fetchBlob(const ORMUuid &blobUuid, std::basic_string<std::byte> &data)
{
    t0035_blobs t0035;
    if (!selectObject(blobUuid, t0035))
    {
        return false;
    }
    return sqlInterface.fetchBlob(t0035.blob_oid, data);
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
