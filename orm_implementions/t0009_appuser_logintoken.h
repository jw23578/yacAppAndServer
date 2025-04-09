#ifndef T0009_APPUSER_LOGINTOKEN_H
#define T0009_APPUSER_LOGINTOKEN_H

#include "yacbaseobject.h"

class t0009_appuser_logintoken : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(appuser_logintoken_id);
    MACRO_UUID_PROPERTY(appuser_id);
    MACRO_STRING_PROPERTY(login_token);
    MACRO_DATETIME_PROPERTY(login_token_valid_until);

public:
    t0009_appuser_logintoken():YACBaseObject(Rights::RN_noOne)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(appuser_logintoken_id, DetailID);
        MACRO_ADD_PROPERTY(appuser_id);
        MACRO_ADD_PROPERTY(login_token);
        MACRO_ADD_PROPERTY(login_token_valid_until);
    }
    const ORMString getORMName() const override
    {
        return "t0009_appuser_logintoken";
    }
    YACBaseObject *create() const override
    {
        return new t0009_appuser_logintoken;
    }
};

#endif // T0009_APPUSER_LOGINTOKEN_H
