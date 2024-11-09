#ifndef T0016_APPOINTMENT_TEMPLATES_H
#define T0016_APPOINTMENT_TEMPLATES_H

#include "yacbaseobject.h"

class t0016_appointment_templates : public YACBaseObject
{
    Q_OBJECT
MACRO_UUID_PROPERTY(app_id);
MACRO_STRING_PROPERTY(name);
MACRO_INT_PROPERTY(default_duration_in_minutes);
MACRO_INT_PROPERTY(color);
MACRO_UUID_PROPERTY(owner_id);
public:
MACRO_CREATE_AND_GETORMNAME(t0016_appointment_templates)
t0016_appointment_templates():YACBaseObject(Rights::RN_everybody)
{
    MACRO_ADD_INDEX_PROPERTY(app_id);
    MACRO_ADD_PROPERTY(name);
    MACRO_ADD_PROPERTY(default_duration_in_minutes);
    MACRO_ADD_PROPERTY(color);
    MACRO_ADD_PROPERTY(owner_id);
}
};

#endif // T0016_APPOINTMENT_TEMPLATES_H
