#include "t0002_apps.h"
#include "t0036_rythm.h"

void t0002_apps::createDefaults(ORMPersistenceInterface &opi)
{
    if (!opi.selectObject({{theSystemUser.fstnameORM().name(), "theSystemUser"},
                           {theSystemUser.surnameORM().name(), "theSystemUser"}}, theSystemUser))
    {
        theSystemUser.prepareFirstInsert();
        theSystemUser.setfstname("theSystemUser");
        theSystemUser.setsurname("theSystemUser");
        theSystemUser.setapp_id(getapp_id());
#ifdef ONLY_INSERT_DB_CREATED_BY_COLUMN
        opi.insertObject(theSystemUser, theSystemUser.getappuser_profile_id());
#else
        opi.insertObject(theSystemUser);
#endif
    }

    t0036_rythm daily;
    if (!opi.selectObject({{daily.rythm_nameORM().name(), "daily"},
                           {daily.app_idORM().name(), idORM().asString()}}, daily))
    {
        daily.prepareFirstInsert();
        daily.setapp_id(getapp_id());
        daily.setrythm_name("daily");
        daily.setdefault_rythm(true);
        daily.setrepeat_every_days(1);
#ifdef ONLY_INSERT_DB_CREATED_BY_COLUMN
        opi.insertObject(daily, theSystemUser.getappuser_profile_id());
#else
        opi.insertObject(daily);
#endif
    }
    t0036_rythm weekly;
    if (!opi.selectObject({{weekly.rythm_nameORM().name(), "weekly"},
                           {weekly.app_idORM().name(), idORM().asString()}}, weekly))
    {
        weekly.prepareFirstInsert();
        weekly.setapp_id(getapp_id());
        weekly.setrythm_name("weekly");
        weekly.setdefault_rythm(true);
        weekly.setrepeat_every_days(7);
#ifdef ONLY_INSERT_DB_CREATED_BY_COLUMN
        opi.insertObject(weekly, theSystemUser.getappuser_profile_id());
#else
        opi.insertObject(weekly);
#endif
    }
    t0036_rythm monthly;
    if (!opi.selectObject({{monthly.rythm_nameORM().name(), "monthly"},
                           {monthly.app_idORM().name(), idORM().asString()}}, monthly))
    {
        monthly.prepareFirstInsert();
        monthly.setapp_id(getapp_id());
        monthly.setrythm_name("monthly");
        monthly.setdefault_rythm(true);
        monthly.setrepeat_every_months(1);
#ifdef ONLY_INSERT_DB_CREATED_BY_COLUMN
        opi.insertObject(monthly, theSystemUser.getappuser_profile_id());
#else
        opi.insertObject(monthly);
#endif
    }
}
