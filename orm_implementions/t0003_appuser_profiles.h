#ifndef T0003_APPUSER_PROFILES_H
#define T0003_APPUSER_PROFILES_H

#include "yacbaseobject.h"

class t0003_appuser_profiles : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(app_id);
    MACRO_STRING_PROPERTY(fstname);
    MACRO_STRING_PROPERTY(surname);
    MACRO_STRING_PROPERTY(visible_name);
    MACRO_STRING_PROPERTY(color);
    MACRO_STRING_PROPERTY(loginemail);
    MACRO_DATETIME_PROPERTY(verified);
    MACRO_STRING_PROPERTY(verify_token);
    MACRO_DATETIME_PROPERTY(verify_token_valid_until);
    MACRO_STRING_PROPERTY(update_password_token);
    MACRO_DATETIME_PROPERTY(update_password_token_valid_until);
    MACRO_DATETIME_PROPERTY(deleted);
    MACRO_BOOL_PROPERTY(searching_exactly_allowed);
    MACRO_BOOL_PROPERTY(searching_fuzzy_allowed);
    MACRO_STRING_PROPERTY(public_key_base64);
    MACRO_UUID_PROPERTY(image_id);

public:
    t0003_appuser_profiles():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_INDEX_PROPERTY(app_id);
        MACRO_ADD_PROPERTY(fstname);
        MACRO_ADD_PROPERTY(surname);
        MACRO_ADD_PROPERTY(visible_name);
        MACRO_ADD_PROPERTY(color);
        MACRO_ADD_INDEX_PROPERTY(loginemail);
        MACRO_ADD_PROPERTY(verified);
        MACRO_ADD_PROPERTY(verify_token);
        MACRO_ADD_PROPERTY(verify_token_valid_until);
        MACRO_ADD_PROPERTY(update_password_token);
        MACRO_ADD_PROPERTY(update_password_token_valid_until);
        MACRO_ADD_PROPERTY(deleted);
        MACRO_ADD_PROPERTY(searching_exactly_allowed);
        MACRO_ADD_PROPERTY(searching_fuzzy_allowed);
        MACRO_ADD_PROPERTY(public_key_base64);
        MACRO_ADD_PROPERTY(image_id);
    }
    const ORMString getORMName() const override
    {
        return "t0003_appuser_profiles";
    }
    YACBaseObject *create() const override
    {
        return new t0003_appuser_profiles;
    }
};

#endif // T0003_APPUSER_PROFILES_H
