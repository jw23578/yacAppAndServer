#ifndef ORMPERSISTENCEINTERFACE_H
#define ORMPERSISTENCEINTERFACE_H

#include <cstddef>
#include "ormobjectinterface.h"
#include "ormsqlinterface.h"

class ORMPersistenceInterface
{
    ORMSqlInterface &sqlInterface;
public:
    ORMPersistenceInterface(ORMSqlInterface &sqlInterface);

    virtual size_t storeBlob() = 0;

    void insertObject(ORMObjectInterface const &object);
    virtual bool selectObject(ORMPropertyUuid &id, ORMObjectInterface &target) = 0;
    virtual bool updateObject(ORMObjectInterface const &object) = 0;

    virtual ~ORMPersistenceInterface() {}
};

#endif // ORMPERSISTENCEINTERFACE_H
