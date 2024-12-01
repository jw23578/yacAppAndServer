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
public:
    const RightNumber changeRight;


    YACBaseObject(RightNumber changeRight):ORMObjectInterface(),
        changeRight(changeRight)
    {
        MACRO_ADD_PROPERTY(id);
        MACRO_ADD_DETAIL(id, DetailID);
    }
    void generateID();
    void assign(const YACBaseObject &other);
};



#endif // YACBASEOBJECT_H
