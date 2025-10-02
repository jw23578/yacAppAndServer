#include "t0001_apps.h"
#include "t0036_rythm.h"

void t0001_apps::createDefaults(CurrentContext &context)
{
    if (!theSuperUser.load(context,
                           {{theSuperUser.fstnameORM().name(), context.superUserFstname},
                           {theSuperUser.surnameORM().name(), context.superUserSurname}}))
    {
        theSuperUser.setfstname(context.superUserFstname);
        theSuperUser.setsurname(context.superUserSurname);
        theSuperUser.store(context);
    }

    t0036_rythm daily;
    if (!daily.load(context,
                    {{daily.rythm_nameORM().name(), "daily"},
                     {daily.app_idORM().name(), idORM().asString()}}))
    {
        daily.setrythm_name("daily");
        daily.setdefault_rythm(true);
        daily.setrepeat_every_days(1);
        daily.store(context);
    }
    t0036_rythm weekly;
    if (!weekly.load(context,
                     {{weekly.rythm_nameORM().name(), "weekly"},
                      {weekly.app_idORM().name(), idORM().asString()}}))
    {
        weekly.setrythm_name("weekly");
        weekly.setdefault_rythm(true);
        weekly.setrepeat_every_days(7);
        weekly.store(context);
    }
    t0036_rythm monthly;
    if (!monthly.load(context,
                      {{monthly.rythm_nameORM().name(), "monthly"},
                       {monthly.app_idORM().name(), idORM().asString()}}))
    {
        monthly.setrythm_name("monthly");
        monthly.setdefault_rythm(true);
        monthly.setrepeat_every_months(1);
        monthly.store(context);
    }
}
