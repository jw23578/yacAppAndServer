#ifndef APPBASEOBJECT_H
#define APPBASEOBJECT_H

#include "yacbaseobject.h"

class AppBaseObject : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(app_id);
public:
    AppBaseObject(const RightNumber changeRight):YACBaseObject(changeRight)
    {
        MACRO_ADD_INDEX_PROPERTY(app_id);
    }

};

#endif // APPBASEOBJECT_H
