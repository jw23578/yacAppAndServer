#ifndef YACBASEOBJECT_H
#define YACBASEOBJECT_H

#include "orm/ormobjectinterface.h".h"
#include "rightnumbers.h"
#include "tablefields.h"

class YACBaseObject : public ORMObjectInterface
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif


    MACRO_UUID_PROPERTY(id);
public:
    const RightNumber changeRight;


    YACBaseObject(RightNumber changeRight):ORMObjectInterface(),
        changeRight(changeRight)
    {
        MACRO_ADD_PROPERTY(id);
    }

    void assign(const YACBaseObject &other);
};

#endif // YACBASEOBJECT_H
