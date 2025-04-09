#include "t0002_apps.h"
#include "t0036_rythm.h"

#include "t0004_appuser_passwordhashes.h"
void t0002_apps::createDefaults(ORMPersistenceInterface &opi)
{
    if (!opi.selectObject({{theSystemUser.fstname.name(), "theSystemUser"},
                           {theSystemUser.surname.name(), "theSystemUser"}}, theSystemUser))
    {
        theSystemUser.prepareFirstInsert();
        theSystemUser.setfstname("theSystemUser");
        theSystemUser.setsurname("theSystemUser");
        theSystemUser.app_id = app_id;
        opi.insertObject(theSystemUser, theSystemUser.appuser_profile_id);
    }

    t0036_rythm daily;
    if (!opi.selectObject({{daily.rythm_name.name(), "daily"},
                           {daily.app_id.name(), id.asString()}}, daily))
    {
        daily.prepareFirstInsert();
        daily.app_id = app_id;
        daily.setrythm_name("daily");
        daily.setdefault_rythm(true);
        daily.setrepeat_every_days(1);
        opi.insertObject(daily, theSystemUser.appuser_profile_id);
    }
    t0036_rythm weekly;
    if (!opi.selectObject({{weekly.rythm_name.name(), "weekly"},
                           {weekly.app_id.name(), id.asString()}}, weekly))
    {
        weekly.prepareFirstInsert();
        weekly.app_id = app_id;
        weekly.setrythm_name("weekly");
        weekly.setdefault_rythm(true);
        weekly.setrepeat_every_days(7);
        opi.insertObject(weekly, theSystemUser.appuser_profile_id);
    }
    t0036_rythm monthly;
    if (!opi.selectObject({{monthly.rythm_name.name(), "monthly"},
                           {monthly.app_id.name(), id.asString()}}, monthly))
    {
        monthly.prepareFirstInsert();
        monthly.app_id = app_id;
        monthly.setrythm_name("monthly");
        monthly.setdefault_rythm(true);
        monthly.setrepeat_every_months(1);
        opi.insertObject(monthly, theSystemUser.appuser_profile_id);
    }
}
