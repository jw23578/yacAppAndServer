#ifndef T___5_GROUP_OF_APPUSERS_H
#define T___5_GROUP_OF_APPUSERS_H

#include "appbaseobject.h"

class t0005_group_of_appusers : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(group_of_users_id);
    MACRO_STRING_PROPERTY(name);

public:
    MACRO_CREATE_AND_GETORMNAME(t0005_group_of_appusers)
    t0005_group_of_appusers():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(group_of_users_id, DetailID);
        MACRO_ADD_PROPERTY(name);
    }
};

#endif // T___5_GROUP_OF_APPUSERS_H
