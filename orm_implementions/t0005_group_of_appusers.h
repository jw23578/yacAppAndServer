#ifndef T___5_GROUP_OF_APPUSERS_H
#define T___5_GROUP_OF_APPUSERS_H

#include "yacbaseobject.h"

class t0005_group_of_appusers : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_STRING_PROPERTY(name);

public:
    MACRO_CREATE_AND_GETORMNAME(t0005_group_of_appusers)
    t0005_group_of_appusers():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY(name);
    }
};

#endif // T___5_GROUP_OF_APPUSERS_H
