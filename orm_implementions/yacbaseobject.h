#ifndef YACBASEOBJECT_H
#define YACBASEOBJECT_H

#include "orm/ormobjectinterface.h"
#include "rightnumbers.h"
#include "tablefields.h"


#define MACRO_CREATE_AND_GETORMNAME(name) \
const ORMString getORMName() const override \
{ \
return #name; \
} \
YACBaseObject *create() const override \
{ \
    return new name; \
}


class YACBaseObject : public ORMObjectInterface
{
    Q_OBJECT

    MACRO_UUID_PROPERTY(id);
    MACRO_DATETIME_PROPERTY(created);
    MACRO_UUID_PROPERTY(created_by_t0003_id)
    MACRO_DATETIME_PROPERTY(historied);
    MACRO_DATETIME_PROPERTY(deleted);
    MACRO_UUID_PROPERTY(deleted_by_t0003_id)
public:
    const RightNumber changeRight;


    YACBaseObject(RightNumber changeRight):ORMObjectInterface(),
        changeRight(changeRight)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(id, DetailDBPrimaryKey);
        MACRO_ADD_DETAIL(id, DetailDBSystemInfo);
        MACRO_ADD_PROPERTY_ADD_DETAIL(created, DetailDBSystemInfo);
        MACRO_ADD_PROPERTY_ADD_DETAIL(created_by_t0003_id, DetailDBSystemInfo);
        MACRO_ADD_PROPERTY_ADD_DETAIL(historied, DetailDBSystemInfo);
        MACRO_ADD_DETAIL(historied, DetailDBHstoriedDateTime);
        MACRO_ADD_PROPERTY_ADD_DETAIL(deleted, DetailDBSystemInfo);
        MACRO_ADD_DETAIL(deleted, DetailDBDeletedDateTime);
        MACRO_ADD_PROPERTY_ADD_DETAIL(deleted_by_t0003_id, DetailDBSystemInfo);
    }
    void prepareFirstInsert();
    void assign(const YACBaseObject &other);
};



#endif // YACBASEOBJECT_H
