#include "ormpersistenceinterface.h"

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

}

bool ORMPersistenceInterface::updateObject(const ORMObjectInterface &object)
{

}

bool ORMPersistenceInterface::upsertObject(ORMObjectInterface &object)
{
    if (object.propertyIsNull("id"))
    {
        object.setPropertyFromString("id", uuidToString(generateUuid()));
        return insertObject(object);
    }
    return updateObject(object);
}
