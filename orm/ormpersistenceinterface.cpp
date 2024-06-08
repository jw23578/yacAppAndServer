#include "ormpersistenceinterface.h"
#include "utils/extuuid.h"

ORMPersistenceInterface::ORMPersistenceInterface(ORMSqlInterface &sqlInterface):sqlInterface(sqlInterface) {}

bool ORMPersistenceInterface::insertObject(const ORMObjectInterface &object)
{
    SqlString sql;
    sql.insert(object.getORMName());
    const std::set<ORMString> &propertyNames(object.propertyNames());
    for (auto &n: propertyNames)
    {
        sql.addInsert(n, object.getPropertyToString(n));
    }
    return sqlInterface.execute(sql);
}

bool ORMPersistenceInterface::selectObject(ORMPropertyUuid &id, ORMObjectInterface &target)
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
        target.setPropertyFromString(n, sqlInterface.value(n).value());
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
        if (n != tableFields.id)
        {
            sql.addSet(n, object.getPropertyToString(n));
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
