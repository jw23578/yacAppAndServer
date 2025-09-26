#ifndef T0002_USER_H
#define T0002_USER_H

#include "appbaseobject.h"

class t0002_user : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(user_id);
    MACRO_STRING_PROPERTY(fstname);
    MACRO_STRING_PROPERTY(surname);
    MACRO_STRING_PROPERTY(visible_name);
    MACRO_STRING_PROPERTY(color);
    MACRO_STRING_PROPERTY(message_font_color);
    MACRO_STRING_PROPERTY(loginemail);
    MACRO_DATETIME_PROPERTY(verified);
    MACRO_STRING_PROPERTY(verify_token);
    MACRO_DATETIME_PROPERTY(verify_token_valid_until);
    MACRO_STRING_PROPERTY(update_password_token);
    MACRO_DATETIME_PROPERTY(update_password_token_valid_until);
    MACRO_BOOL_PROPERTY(searching_exactly_allowed);
    MACRO_BOOL_PROPERTY(searching_fuzzy_allowed);
    MACRO_STRING_PROPERTY(public_key_base64);
    MACRO_UUID_PROPERTY(image_id);
    MACRO_BOOL_PROPERTY(super_user);

public:
    t0002_user():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(user_id, DetailID);
        MACRO_ADD_PROPERTY(fstname);
        MACRO_ADD_PROPERTY(surname);
        MACRO_ADD_PROPERTY(visible_name);
        MACRO_ADD_PROPERTY(color);
        MACRO_ADD_PROPERTY(message_font_color);
        MACRO_ADD_INDEX_PROPERTY(loginemail);
        MACRO_ADD_PROPERTY(verified);
        MACRO_ADD_PROPERTY(verify_token);
        MACRO_ADD_PROPERTY(verify_token_valid_until);
        MACRO_ADD_PROPERTY(update_password_token);
        MACRO_ADD_PROPERTY(update_password_token_valid_until);
        MACRO_ADD_PROPERTY(searching_exactly_allowed);
        MACRO_ADD_PROPERTY(searching_fuzzy_allowed);
        MACRO_ADD_PROPERTY(public_key_base64);
        MACRO_ADD_PROPERTY(image_id);
        MACRO_ADD_PROPERTY(super_user);
    }
    MACRO_CREATE_AND_GETORMNAME(t0002_user)

    void clearUpdatePasswordToken();
    bool loadByLoginEMail(ORMPersistenceInterface &opi,
                          const reducedsole::uuid &appId,
                          const ORMString &loginEMail);
};

#endif // T0002_USER_H
