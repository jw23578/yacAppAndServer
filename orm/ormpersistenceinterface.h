#ifndef ORMPERSISTENCEINTERFACE_H
#define ORMPERSISTENCEINTERFACE_H

#include <cstddef>
#include "ormobjectinterface.h"
#include "ormsqlinterface.h"
#include "tablefields.h"
#include "ormvector.h"

class ORMPersistenceInterface
{
    TableFields tableFields;
    ORMSqlInterface &sqlInterface;
public:
    ORMPersistenceInterface(ORMSqlInterface &sqlInterface);

    bool insertObject(ORMObjectInterface const &object) const;
    bool selectObject(ORMUuid const &id, ORMObjectInterface &target);
    bool updateObject(ORMObjectInterface const &object);
    bool upsertObject(ORMObjectInterface &object);
    bool deleteObject(ORMObjectInterface &object);

    bool sameDataExists(ORMObjectInterface &object) const;
    bool insertIfNotSameDataExists(ORMObjectInterface &object) const;

    size_t fetchIDs(SqlString const &sql,
                    std::set<ORMUuid> &ids);
    template<class T>
    size_t fetchObjects(SqlString const &sql, ORMVector<T> &target)
    {
        if (!sqlInterface.open(sql))
        {
            return 0;
        }
        for (size_t i(0); i < sqlInterface.size(); ++i)
        {
            target.append().fill(sqlInterface);
            sqlInterface.next();
        }
        return target.size();
    }

    ORMUuid storeBlob(std::basic_string<std::byte> const &data);
    bool fetchBlob(const ORMUuid &blobUuid, std::basic_string<std::byte> &data);
    bool deleteBlob(const ORMUuid &blobUuid);

    virtual ~ORMPersistenceInterface() {}
};

#endif // ORMPERSISTENCEINTERFACE_H
