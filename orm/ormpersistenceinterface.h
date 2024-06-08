#ifndef ORMPERSISTENCEINTERFACE_H
#define ORMPERSISTENCEINTERFACE_H

#include <cstddef>
#include "ormobjectinterface.h"
#include "ormsqlinterface.h"
#include "tablefields.h"

class ORMPersistenceInterface
{
    TableFields tableFields;
    ORMSqlInterface &sqlInterface;
public:
    ORMPersistenceInterface(ORMSqlInterface &sqlInterface);

    bool insertObject(ORMObjectInterface const &object);
    bool selectObject(ORMPropertyUuid &id, ORMObjectInterface &target);
    bool updateObject(ORMObjectInterface const &object);
    bool upsertObject(ORMObjectInterface &object);
    bool deleteObject(ORMObjectInterface &object);

    virtual ~ORMPersistenceInterface() {}
};

#endif // ORMPERSISTENCEINTERFACE_H
