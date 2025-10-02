#ifndef T___8_MESSAGE_RECEIVED_H
#define T___8_MESSAGE_RECEIVED_H

#include "appbaseobject.h"

class t0008_message_received : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(message_received_id);
    MACRO_UUID_PROPERTY(message_id);
    MACRO_UUID_PROPERTY(receiver_id);
    MACRO_DATETIME_PROPERTY(received_datetime);
public:
    MACRO_CREATE_AND_GETORMNAME(t0008_message_received)
    t0008_message_received():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(message_received_id, DetailID);
        MACRO_ADD_PROPERTY(message_id);
        MACRO_ADD_PROPERTY(receiver_id);
        MACRO_ADD_PROPERTY(received_datetime);
    }
};

#endif // T___8_MESSAGE_RECEIVED_H
