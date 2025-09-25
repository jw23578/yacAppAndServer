#ifndef T0029_THIRD_PARTY_USER_DATA_H
#define T0029_THIRD_PARTY_USER_DATA_H

#include "yacbaseobject.h"

class t0029_third_party_user_data : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(app_id);
    MACRO_STRING_PROPERTY(user_id_string);
    MACRO_STRING_PROPERTY(third_party_string);
    MACRO_STRING_PROPERTY(image_id_string);
    MACRO_UUID_PROPERTY(appuser_id);
public:
    MACRO_CREATE_AND_GETORMNAME(t0029_third_party_user_data)
    t0029_third_party_user_data():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_INDEX_PROPERTY(app_id);
        MACRO_ADD_INDEX_PROPERTY(user_id_string);
        MACRO_ADD_INDEX_PROPERTY(third_party_string);
        MACRO_ADD_INDEX_PROPERTY(appuser_id);
        MACRO_ADD_PROPERTY(image_id_string);
    }
};

#endif // T0029_THIRD_PARTY_USER_DATA_H
