#ifndef T0001_USERS_H
#define T0001_USERS_H

#include "yacbaseobject.h"

class t0001_users : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(user_id);
    MACRO_STRING_PROPERTY(loginemail);
    MACRO_STRING_PROPERTY(password_hash);
    MACRO_DATETIME_PROPERTY(verified);
    MACRO_STRING_PROPERTY(verify_token);
    MACRO_DATETIME_PROPERTY(verify_token_valid_until);
    MACRO_STRING_PROPERTY(login_token);
    MACRO_DATETIME_PROPERTY(login_token_valid_until);

public:
    MACRO_CREATE_AND_GETORMNAME(t0001_users)
    t0001_users():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(user_id, DetailID);
        MACRO_ADD_INDEX_PROPERTY(loginemail);
        MACRO_ADD_PROPERTY(password_hash);
        MACRO_ADD_PROPERTY(verified);
        MACRO_ADD_PROPERTY(verify_token);
        MACRO_ADD_PROPERTY(verify_token_valid_until);
        MACRO_ADD_PROPERTY(login_token);
        MACRO_ADD_PROPERTY(login_token_valid_until);

        MACRO_ADD_NOTRANSFER_PROPERTY(password_hash);
        MACRO_ADD_NOTRANSFER_PROPERTY(verify_token);
        MACRO_ADD_NOTRANSFER_PROPERTY(login_token);
    }
};

#endif // T0001_USERS_H
