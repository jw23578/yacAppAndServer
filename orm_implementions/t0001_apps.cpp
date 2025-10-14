#include "t0001_apps.h"
#include "t0036_rythm.h"

t0001_apps t0001_apps::theCreatorApp;

void t0001_apps::createDefaults(CurrentContext &context)
{
    CurrentContext localContext(context.opi, app_idORM().get(), context.userId);
    if (!theSuperUser.load(localContext,
                           {{theSuperUser.fstnameORM().name(), context.superUserFstname},
                            {theSuperUser.surnameORM().name(), context.superUserSurname}}))
    {
        theSuperUser.setfstname(context.superUserFstname);
        theSuperUser.setsurname(context.superUserSurname);
        theSuperUser.store(localContext);
    }

    t0036_rythm daily;
    if (!daily.load(localContext,
                    {{daily.rythm_nameORM().name(), "daily"}}))
    {
        daily.setrythm_name("daily");
        daily.setdefault_rythm(true);
        daily.setrepeat_every_days(1);
        daily.store(localContext);
    }
    t0036_rythm weekly;
    if (!weekly.load(localContext,
                     {{weekly.rythm_nameORM().name(), "weekly"}}))
    {
        weekly.setrythm_name("weekly");
        weekly.setdefault_rythm(true);
        weekly.setrepeat_every_days(7);
        weekly.store(localContext);
    }
    t0036_rythm monthly;
    if (!monthly.load(localContext,
                      {{monthly.rythm_nameORM().name(), "monthly"}}))
    {
        monthly.setrythm_name("monthly");
        monthly.setdefault_rythm(true);
        monthly.setrepeat_every_months(1);
        monthly.store(localContext);
    }
}

bool t0001_apps::userIsAppOwner(const ORMUuid &app_id,
                                const ORMUuid &user_id,
                                std::string &errorMessage,
                                bool &appExists)
{
    appExists = true;
    // FIXME
    return true;
    /*    PGUtils utils(pool);
    t0002_apps t0002;
    SqlString sql(utils.createEntryExistsString(t0002.getORMName(), tableFields.id));
    sql.set(tableFields.id, app_id);
    PGExecutor e(pool, sql);
    appExists = e.size() > 0;
    if (e.size())
    {
        if (e.uuid("owner_id") != user_id)
        {
            errorMessage = "user is not app owner";
            return false;
        }
    }
    return true; */
}

#ifndef ORMQTTypes
bool t0001_apps::saveApp(CurrentContext &context,
                         t0001_apps &app,
                         const ORMString &installation_code,
                         std::string &message)
{
    bool appExists(false);
    if (!userIsAppOwner(app.app_idORM().get(), context.userId, message, appExists))
    {
        return false;
    }
    app.yacpck_base64ORM().set(context.opi.storeBlob(app.transfer_yacpck_base64ORM().get(), context.userId));
    app.owner_idORM().set(context.userId);
    app.installation_code_hashORM().set(installation_code);
    app.store(context);
    return true;
}
#endif

bool t0001_apps::fetchOneApp(CurrentContext &context,
                             const int current_installed_version,
                             const ORMString &installation_code,
                             std::string &message)
{
    SqlString sql("select app_name "
                  ", app_version "
                  ", json_yacapp "
                  ", yacpck_base64 "
                  ", coalesce(installation_code_hash, '') = '' or installation_code_hash = crypt(:installation_code, installation_code_hash) as installation_code_ok "
                  "from t0001_apps ");
    sql.addCompare("where", app_idORM().name(), "=", context.appId);
    context.opi.addOnlyInsertDBWhere(false, sql);
    MACRO_set(sql, installation_code);

    size_t count(0);
    if (!context.opi.selectObject(sql,
                                  *this,
                                  count))
    {
        message = "app not found";
        return false;
    }
    if (!installation_code_okORM().get())
    {
        message = "wrong installation code";
        return false;
    }
    if (app_versionORM().get() <= current_installed_version)
    {
        message = "app version is up to date";
        return true;
    }
    return true;
}


size_t t0001_apps::getAllAPPs(CurrentContext &context, ORMVector<t0001_apps> &target)
{
    SqlString sql("select app_id "
                  ", app_name "
                  ", app_version "
                  ", app_logo_url "
                  ", app_color_name "
                  ", app_info_url "
                  ", search_code "
                  ", installation_code_hash "
                  ", array(select app_image_id from t0027_app_images where app_id = t0001.app_id order by position) as app_image_ids "
                  "from t0001_apps t0001 "
                  "where app_version is not null ");
    context.opi.addOnlyInsertDBWhere(false, sql);
    return context.opi.fetchObjects(sql, target);
}
