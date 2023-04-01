#ifndef YACBASEOBJECT_H
#define YACBASEOBJECT_H

#include "orm/ormobjectinterface.h"
#include "rightnumbers.h"

class YACBaseObject : public ORMObjectInterface
{
    MACRO_UUID_PROPERTY(id);
public:
    const RightNumber changeRight;


    YACBaseObject(RightNumber changeRight):ORMObjectInterface(),
        changeRight(changeRight)
    {
        MACRO_ADD_PROPERTY(id);
    }
};

#endif // YACBASEOBJECT_H
