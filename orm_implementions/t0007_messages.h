#ifndef T___7_MESSAGES_H
#define T___7_MESSAGES_H

#include "yacbaseobject.h"

class t0007_messages : public YACBaseObject
{
    MACRO_UUID_PROPERTY(message_id);
    MACRO_UUID_PROPERTY(sender_id);
    MACRO_UUID_PROPERTY(to_id);
    MACRO_DATETIME_PROPERTY(sended_datetime);
    MACRO_STRING_PROPERTY(content_base64);
public:
    MACRO_CREATE_AND_GETORMNAME(t0007_messages)
    t0007_messages():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(message_id, DetailID);
        MACRO_ADD_PROPERTY(sender_id);
        MACRO_ADD_PROPERTY(to_id);
        MACRO_ADD_PROPERTY(sended_datetime);
        MACRO_ADD_PROPERTY(content_base64);
    }
};

#endif // T___7_MESSAGES_H
