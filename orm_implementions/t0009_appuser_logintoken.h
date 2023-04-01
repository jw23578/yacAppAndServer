#ifndef T0009_APPUSER_LOGINTOKEN_H
#define T0009_APPUSER_LOGINTOKEN_H

#include "yacbaseobject.h"

class t0009_appuser_logintoken : public YACBaseObject
{
public:
    MACRO_DECLARE_PROPERTY(ORMPropertyUuid, appuser_id);
    MACRO_DECLARE_PROPERTY(ORMPropertyString, login_token);
    MACRO_DECLARE_PROPERTY(ORMPropertyDateTime, login_token_valid_until);

    t0009_appuser_logintoken():YACBaseObject(Rights::RN_noOne)
    {
        MACRO_ADD_PROPERTY(appuser_id);
        MACRO_ADD_PROPERTY(login_token);
        MACRO_ADD_PROPERTY(login_token_valid_until);
    }
    const ORMString getORMName() const override
    {
        return "t0009_appuser_logintoken";
    }
    ORMObjectInterface *create() const override
    {
        return new t0009_appuser_logintoken;
    }

};

#endif // T0009_APPUSER_LOGINTOKEN_H
