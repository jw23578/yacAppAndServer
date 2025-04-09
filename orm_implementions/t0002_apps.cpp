#include "t0002_apps.h"
#include "t0036_rythm.h"


void t0002_apps::createDefaults(ORMPersistenceInterface &opi) const
{
    t0036_rythm daily;
    if (!opi.selectObject({{daily.rythm_name.name(), "daily"},
                           {daily.app_id.name(), id.asString()}}, daily))
    {
        daily.generateID();
        daily.app_id = id;
        daily.setrythm_name("daily");
        daily.setdefault_rythm(true);
        daily.setrepeat_every_days(1);
        opi.insertObject(daily);
    }
    t0036_rythm weekly;
    if (!opi.selectObject({{weekly.rythm_name.name(), "weekly"},
                           {weekly.app_id.name(), id.asString()}}, weekly))
    {
        weekly.generateID();
        weekly.app_id = id;
        weekly.setrythm_name("weekly");
        weekly.setdefault_rythm(true);
        weekly.setrepeat_every_days(7);
        opi.insertObject(weekly);
    }
    t0036_rythm monthly;
    if (!opi.selectObject({{monthly.rythm_name.name(), "monthly"},
                           {monthly.app_id.name(), id.asString()}}, monthly))
    {
        monthly.generateID();
        monthly.app_id = id;
        monthly.setrythm_name("monthly");
        monthly.setdefault_rythm(true);
        monthly.setrepeat_every_months(1);
        opi.insertObject(monthly);
    }
}
