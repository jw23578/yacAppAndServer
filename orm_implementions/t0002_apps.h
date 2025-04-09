#ifndef T0002_APPS_H
#define T0002_APPS_H

#include "yacbaseobject.h"
#include "orm/ormpersistenceinterface.h"

class t0002_apps : public YACBaseObject
{
    Q_OBJECT

    MACRO_UUID_PROPERTY(owner_id);
    MACRO_STRING_PROPERTY(app_name);
    MACRO_INT_PROPERTY(app_version);
    MACRO_STRING_PROPERTY(app_logo_url);
    MACRO_STRING_PROPERTY(app_color_name);
    MACRO_BOOL_PROPERTY(is_template_app);
    MACRO_STRING_PROPERTY(json_yacapp);
    MACRO_OID_PROPERTY(yacpck_base64);
    MACRO_STRING_PROPERTY(app_info_url);
    MACRO_STRING_PROPERTY(search_code);
    MACRO_STRING_PROPERTY(installation_code_hash);

    MACRO_STRING_PROPERTY(transfer_yacpck_base64);
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
        MACRO_ADD_PROPERTY(search_code);

        MACRO_ADD_NOTRANSFER_PROPERTY(installation_code_hash);

        MACRO_ADD_TRANSFER_PROPERTY(transfer_yacpck_base64);
    }
    const ORMString getORMName() const override
    {
        return "t0002_apps";
    }
    YACBaseObject *create() const override
    {
        return new t0002_apps;
    }

    void createDefaults(ORMPersistenceInterface &opi) const;
};

#endif // T0002_APPS_H

