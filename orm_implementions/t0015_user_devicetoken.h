#ifndef T__15_APPUSER_DEVICETOKEN_H
#define T__15_APPUSER_DEVICETOKEN_H

#include "appbaseobject.h"

class t0015_user_devicetoken : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(user_devicetoken_id);
    MACRO_UUID_PROPERTY(user_id);
    MACRO_STRING_PROPERTY(device_token);
public:
    MACRO_CREATE_AND_GETORMNAME(t0015_user_devicetoken)

    t0015_user_devicetoken():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(user_devicetoken_id, DetailID);
        MACRO_ADD_PROPERTY(user_id);
        MACRO_ADD_PROPERTY(device_token);
    }

    size_t fetchDeviceToken(CurrentContext &context,
                            const ORMUuid &userId,
                            std::set<ORMString> &deviceTokenSet);
};

#endif // T__15_APPUSER_DEVICETOKEN_H
