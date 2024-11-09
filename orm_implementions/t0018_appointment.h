#ifndef T0018_APPOINTMENT_H
#define T0018_APPOINTMENT_H

#include "yacbaseobject.h"

class t0018_appointment: public YACBaseObject
{
    Q_OBJECT
MACRO_UUID_PROPERTY(app_id);
MACRO_UUID_PROPERTY(appointment_group_id);
MACRO_UUID_PROPERTY(appointment_template_id);
MACRO_STRING_PROPERTY(caption);
MACRO_STRING_PROPERTY(decription);
MACRO_DATETIME_PROPERTY(start_datetime);
MACRO_DATETIME_PROPERTY(end_datetime);
MACRO_UUID_PROPERTY(creater_id);
MACRO_DATETIME_PROPERTY(bookable_since_datetime);
MACRO_DATETIME_PROPERTY(bookable_until_datetime);
MACRO_INT_PROPERTY(booking_credits);
MACRO_BOOL_PROPERTY(visible_for_everybody);
MACRO_BOOL_PROPERTY(no_space);
public:
MACRO_CREATE_AND_GETORMNAME(t0018_appointment)
t0018_appointment():YACBaseObject(Rights::RN_everybody)
{
    MACRO_ADD_INDEX_PROPERTY(app_id);
    MACRO_ADD_PROPERTY(appointment_group_id);
    MACRO_ADD_PROPERTY(appointment_template_id);
    MACRO_ADD_PROPERTY(caption);
    MACRO_ADD_PROPERTY(decription);
    MACRO_ADD_PROPERTY(start_datetime);
    MACRO_ADD_PROPERTY(end_datetime);
    MACRO_ADD_PROPERTY(creater_id);
    MACRO_ADD_PROPERTY(bookable_since_datetime);
    MACRO_ADD_PROPERTY(bookable_until_datetime);
    MACRO_ADD_PROPERTY(booking_credits);
    MACRO_ADD_PROPERTY(visible_for_everybody);
    MACRO_ADD_PROPERTY(no_space);
}
};

#endif // T0018_APPOINTMENT_H
