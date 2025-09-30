#ifndef T0001_APPS_H
#define T0001_APPS_H

#include "appbaseobject.h"
#include "t0002_user.h"

class t0001_apps : public AppBaseObject
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
    MACRO_OID_PROPERTY(yacpck_base64);
    MACRO_STRING_PROPERTY(app_info_url);
    MACRO_STRING_PROPERTY(search_code);
    MACRO_STRING_PROPERTY(installation_code_hash);

    MACRO_STRING_PROPERTY(transfer_yacpck_base64);

    t0002_user theSuperUser;

public:
    t0001_apps():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_DETAIL(app_id, DetailID);
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
    MACRO_CREATE_AND_GETORMNAME(t0001_apps)

    void createDefaults(CurrentContext &context);
};

#endif // T0001_APPS_H

