#ifndef ORMPERSISTENCEINTERFACE_H
#define ORMPERSISTENCEINTERFACE_H

#include <cstddef>
#include "ormobjectinterface.h"

class ORMPersistenceInterface
{
public:
    ORMPersistenceInterface();

    virtual size_t storeBlob() = 0;

    virtual void insertObject(ORMObjectInterface const &object) = 0;
    virtual bool selectObject(ORMPropertyUuid &id, ORMObjectInterface &target) = 0;
    virtual bool updateObject(ORMObjectInterface const &object) = 0;

    virtual ~ORMPersistenceInterface() {}
};

#endif // ORMPERSISTENCEINTERFACE_H
