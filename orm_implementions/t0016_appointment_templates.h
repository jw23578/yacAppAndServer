#ifndef T0016_APPOINTMENT_TEMPLATES_H
#define T0016_APPOINTMENT_TEMPLATES_H

#include "appbaseobject.h"

class t0016_appointment_templates : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(appointment_template_id)
    MACRO_STRING_PROPERTY(name);
    MACRO_INT_PROPERTY(default_duration_in_minutes);
    MACRO_INT_PROPERTY(color);
public:
    MACRO_CREATE_AND_GETORMNAME(t0016_appointment_templates)
    t0016_appointment_templates():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY(appointment_template_id);
        MACRO_ADD_PROPERTY(name);
        MACRO_ADD_PROPERTY(default_duration_in_minutes);
        MACRO_ADD_PROPERTY(color);
    }
};

#endif // T0016_APPOINTMENT_TEMPLATES_H
