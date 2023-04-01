#ifndef T0009_APPUSER_LOGINTOKEN_H
#define T0009_APPUSER_LOGINTOKEN_H

#include "orm/ormobjectinterface.h"

class t0009_appuser_logintoken : public ORMObjectInterface
{
public:
    ORMPropertyUuid appuser_id;
    ORMPropertyString login_token;
    ORMPropertyDateTime login_token_valid_until;

    t0009_appuser_logintoken():ORMObjectInterface()
    {
        MACRO_addProperty(appuser_id);
        MACRO_addProperty(login_token);
        MACRO_addProperty(login_token_valid_until);
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
