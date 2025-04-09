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

    bool insertObject(ORMObjectInterface &object, const reducedsole::uuid &created_by_t0003_id) const;
    bool existObject(ORMUuid const &id, const ORMObjectInterface &target);
    bool selectObject(ORMUuid const &id, ORMObjectInterface &target);
    bool selectObject(ORMUuid const &id, ORMObjectInterface &target, size_t &count);
    bool selectObject(std::map<ORMString, ORMString> field2needle, ORMObjectInterface &target);
    bool selectObject(std::map<ORMString, ORMString> field2needle, ORMObjectInterface &target, size_t &count);
    bool deleteObject(ORMObjectInterface &object, const reducedsole::uuid &deleted_by_t0003_id);

    bool sameDataExists(ORMObjectInterface &object) const;
    bool insertIfNotSameDataExists(ORMObjectInterface &object, const reducedsole::uuid &created_by_t0003_id) const;

    size_t fetchIDs(SqlString const &sql,
                    std::set<ORMUuid> &ids);

    template<class T>
    size_t fetchAllObjects(ORMVector<T> &target)
    {
        T *ghost(target.createObject());
        SqlString sql;
        sql.select(ghost->getORMName());
        delete ghost;
        return fetchObjects(sql, target);
    }

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

    ORMUuid storeBlob(std::basic_string<std::byte> const &data, const reducedsole::uuid &created_by_t0003_id);
    bool fetchBlob(const ORMUuid &blobUuid, std::basic_string<std::byte> &data);
    bool deleteBlob(const ORMUuid &blobUuid, const reducedsole::uuid &deleted_by_t0003_id);

    virtual ~ORMPersistenceInterface() {}
};

#endif // ORMPERSISTENCEINTERFACE_H
