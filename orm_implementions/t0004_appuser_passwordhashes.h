#ifndef T___4_APPUSER_PASSWORDHASHES_H
#define T___4_APPUSER_PASSWORDHASHES_H

#include "appbaseobject.h"

class t0004_appuser_passwordhashes : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(appuser_passwordhash_id);
    MACRO_UUID_PROPERTY(appuser_id);
    MACRO_STRING_PROPERTY(password_hash);
public:
    MACRO_CREATE_AND_GETORMNAME(t0004_appuser_passwordhashes)
    t0004_appuser_passwordhashes():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(appuser_passwordhash_id, DetailID);
        MACRO_ADD_PROPERTY(appuser_id);
        MACRO_ADD_PROPERTY(password_hash);
    }
};

#endif // T___4_APPUSER_PASSWORDHASHES_H
