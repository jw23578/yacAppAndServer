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
    MACRO_UUID_PROPERTY(yacpck_base64);
    MACRO_STRING_PROPERTY(app_info_url);
    MACRO_STRING_PROPERTY(search_code);
    MACRO_STRING_PROPERTY(installation_code_hash);

    MACRO_STRING_PROPERTY(transfer_yacpck_base64);

    MACRO_BOOL_PROPERTY(installation_code_ok);
    MACRO_VECTOR_PROPERTY(app_image_ids, ORMUuid);

    t0002_user theSuperUser;

public:
    static t0001_apps theCreatorApp;

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

        MACRO_ADD_VIRTUAL_PROPERTY(installation_code_ok);
        MACRO_ADD_VIRTUAL_PROPERTY(app_image_ids);
    }
    MACRO_CREATE_AND_GETORMNAME(t0001_apps)

    void createDefaults(CurrentContext &context);

    bool userIsAppOwner(const ORMUuid &app_id,
                        const ORMUuid &user_id,
                        std::string &errorMessage,
                        bool &appExists);

    bool saveApp(CurrentContext &context,
                 t0001_apps &app,
                 const ORMString &installation_code,
                 std::string &message);

    bool fetchOneApp(CurrentContext &context,
                     const int current_installed_version,
                     const ORMString &installation_code,
                     std::string &message);
    static size_t getAllAPPs(CurrentContext &context,
                             ORMVector<t0001_apps> &target);
};

#endif // T0001_APPS_H

