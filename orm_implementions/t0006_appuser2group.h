#ifndef T___6_APPUSER2GROUP_H
#define T___6_APPUSER2GROUP_H

#include "appbaseobject.h"

class t0006_appuser2group : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(user2group_id)
    MACRO_UUID_PROPERTY(user_id)
    MACRO_UUID_PROPERTY(group_id)

public:
    MACRO_CREATE_AND_GETORMNAME(t0006_appuser2group)
    t0006_appuser2group():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(user2group_id, DetailID);
        MACRO_ADD_PROPERTY(user_id);
        MACRO_ADD_PROPERTY(group_id);
    }
};

#endif // T___6_APPUSER2GROUP_H
