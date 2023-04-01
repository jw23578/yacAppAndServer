#ifndef YACBASEOBJECT_H
#define YACBASEOBJECT_H

#include "orm/ormobjectinterface.h"
#include "rightnumbers.h"

class YACBaseObject : public ORMObjectInterface
{
public:
    const RightNumber changeRight;
    ORMPropertyUuid id;
    YACBaseObject(RightNumber changeRight):ORMObjectInterface(),
        changeRight(changeRight)
    {
        MACRO_addProperty(id);
    }
};

#endif // YACBASEOBJECT_H
