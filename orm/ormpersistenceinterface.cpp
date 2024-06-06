#include "ormpersistenceinterface.h"

ORMPersistenceInterface::ORMPersistenceInterface(ORMSqlInterface &sqlInterface):sqlInterface(sqlInterface) {}

void ORMPersistenceInterface::insertObject(const ORMObjectInterface &object)
{
    SqlString sql;
    sql.insert(object.getORMName());
    const std::set<ORMString> &propertyNames(object.propertyNames());
    for (auto &n: propertyNames)
    {
        sql.addInsert(n, object.getPropertyToString(n));
    }
    sqlInterface.execute(sql);
}
