#ifndef T0002_APPS_H
#define T0002_APPS_H

#include "yacbaseobject.h"

class t0002_apps : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(owner_id);
    MACRO_STRING_PROPERTY(app_name);
    MACRO_INT_PROPERTY(app_version);
    MACRO_STRING_PROPERTY(app_logo_url);
    MACRO_STRING_PROPERTY(app_color_name);
    MACRO_BOOL_PROPERTY(is_template_app);
    MACRO_STRING_PROPERTY(json_yacapp);
    MACRO_SIZET_PROPERTY(yacpck_base64);
    MACRO_STRING_PROPERTY(app_info_url);
public:
    t0002_apps():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY(owner_id);
        MACRO_ADD_PROPERTY(app_name);
        MACRO_ADD_PROPERTY(app_version);
        MACRO_ADD_PROPERTY(app_logo_url);
        MACRO_ADD_PROPERTY(app_color_name);
        MACRO_ADD_PROPERTY(is_template_app);
        MACRO_ADD_PROPERTY(json_yacapp);
        MACRO_ADD_PROPERTY(yacpck_base64);
        MACRO_ADD_PROPERTY(app_info_url);
    }
    const ORMString getORMName() const override
    {
        return "t0002_apps";
    }
    YACBaseObject *create() const override
    {
        return new t0002_apps;
    }
};

#endif // T0002_APPS_H

