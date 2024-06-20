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
MACRO_CPP_OR_Q_OBJECT

    MACRO_UUID_PROPERTY(id);
public:
    const RightNumber changeRight;


    YACBaseObject(RightNumber changeRight):ORMObjectInterface(),
        changeRight(changeRight)
    {
        MACRO_ADD_PROPERTY(id);
        id.addDetail(DetailID);
    }
    void assign(const YACBaseObject &other);
};

#define MACRO_BEGIN_APP_ORM_OBJECT(name) \
class name : public YACBaseObject \
{ \
MACRO_CPP_OR_Q_OBJECT \
MACRO_UUID_PROPERTY(app_id); \
public: \
MACRO_CREATE_AND_GETORMNAME(name) \
private:



#endif // YACBASEOBJECT_H
