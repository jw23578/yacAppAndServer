#include "ormpersistenceinterface.h"
#include "utils/extuuid.h"
#include "orm_implementions/t0035_blobs.h"

ORMPersistenceInterface::ORMPersistenceInterface(ORMSqlInterface &sqlInterface):sqlInterface(sqlInterface) {}

bool ORMPersistenceInterface::insertObject(const ORMObjectInterface &object)
{
    SqlString sql;
    sql.insert(object.getORMName());
    const std::set<ORMString> &propertyNames(object.propertyNames());
    for (auto &n: propertyNames)
    {
        ORMPropertyInterface *pi(object.getProperty(n));
        if (pi->hasDetail(DetailDB))
        {
            if (pi->isNull())
            {
                sql.addInsertNull(n);
            }
            else
            {
                sql.addInsert(n, pi->asString());
            }
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
    const std::set<ORMString> &propertyNames(target.propertyNames());
    for (auto &n: propertyNames)
    {
        ORMPropertyInterface *pi(target.getProperty(n));
        if (pi->hasDetail(DetailDB))
        {
            pi->fromString(sqlInterface.value(n).value_or(""));
        }
    }
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
            sql.addSet(n, pi->asString());
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
