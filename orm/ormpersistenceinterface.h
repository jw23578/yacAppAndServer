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
    bool selectObject(ORMUuid const &id, ORMObjectInterface &target);
    bool updateObject(ORMObjectInterface const &object);
    bool upsertObject(ORMObjectInterface &object);
    bool deleteObject(ORMObjectInterface &object);

    ORMUuid storeBlob(std::basic_string<std::byte> const &data);
    bool fetchBlob(const ORMUuid &blobUuid, std::basic_string<std::byte> &data);
    bool deleteBlob(const ORMUuid &blobUuid);

    virtual ~ORMPersistenceInterface() {}
};

#endif // ORMPERSISTENCEINTERFACE_H
