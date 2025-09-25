#ifndef T0004_USER_LOGINTOKEN_H
#define T0004_USER_LOGINTOKEN_H

#include "appbaseobject.h"

class t0004_user_logintoken : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(user_logintoken_id);
    MACRO_UUID_PROPERTY(user_id);
    MACRO_STRING_PROPERTY(login_token);
    MACRO_DATETIME_PROPERTY(login_token_valid_until);

public:
    MACRO_CREATE_AND_GETORMNAME(t0004_user_logintoken)
    t0004_user_logintoken():AppBaseObject(Rights::RN_noOne)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(user_logintoken_id, DetailID);
        MACRO_ADD_PROPERTY(user_id);
        MACRO_ADD_PROPERTY(login_token);
        MACRO_ADD_PROPERTY(login_token_valid_until);
    }
};

#endif // T0004_USER_LOGINTOKEN_H
