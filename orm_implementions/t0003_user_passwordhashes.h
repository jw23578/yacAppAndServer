#ifndef T___4_APPUSER_PASSWORDHASHES_H
#define T___4_APPUSER_PASSWORDHASHES_H

#include "appbaseobject.h"

class t0003_user_passwordhashes : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(user_passwordhash_id);
    MACRO_UUID_PROPERTY(user_id);
    MACRO_STRING_PROPERTY(password_hash);
public:
    MACRO_CREATE_AND_GETORMNAME(t0003_user_passwordhashes)
    t0003_user_passwordhashes():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(user_passwordhash_id, DetailID);
        MACRO_ADD_PROPERTY(user_id);
        MACRO_ADD_PROPERTY(password_hash);
    }
    bool login(CurrentContext &context,
               const ORMUuid &userId,
               const ORMString &password,
               std::string &message);
};

#endif // T___4_APPUSER_PASSWORDHASHES_H
