#ifndef YACBASEOBJECT_H
#define YACBASEOBJECT_H

#include "orm/ormobjectinterface.h"
#include "rightnumbers.h"

class YACBaseObject : public ORMObjectInterface
{
public:
    const RightNumber changeRight;
    MACRO_DECLARE_PROPERTY(ORMPropertyUuid, id);
    YACBaseObject(RightNumber changeRight):ORMObjectInterface(),
        changeRight(changeRight)
    {
        MACRO_ADD_PROPERTY(id);
    }
};

#endif // YACBASEOBJECT_H
