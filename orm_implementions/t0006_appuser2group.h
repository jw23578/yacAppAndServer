#ifndef T___6_APPUSER2GROUP_H
#define T___6_APPUSER2GROUP_H

#include "yacbaseobject.h"

class t0006_appuser2group : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(appuser_id)
    MACRO_UUID_PROPERTY(group_id)

public:
    MACRO_CREATE_AND_GETORMNAME(t0006_appuser2group)
    t0006_appuser2group():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY(appuser_id);
        MACRO_ADD_PROPERTY(group_id);
    }
};

#endif // T___6_APPUSER2GROUP_H
