#ifndef T__36_RYTHM_H
#define T__36_RYTHM_H

#include "yacbaseobject.h"
#include <chrono>

class t0036_rythm : public YACBaseObject
{
    Q_OBJECT

    MACRO_UUID_PROPERTY(app_id);
    MACRO_STRING_PROPERTY(rythm_name);
    MACRO_BOOL_PROPERTY(default_rythm);
    MACRO_INT_PROPERTY(repeat_every_months)
    MACRO_INT_PROPERTY(repeat_every_days)
    MACRO_INT_PROPERTY(xth_day_from_month_beginn) // -1 inactive
    MACRO_INT_PROPERTY(xth_day_from_month_end) // -1 inactive
    MACRO_INT_PROPERTY(special_day_of_week) // 0 = Sunday to 6 = Saturday, -1 inactive https://en.cppreference.com/w/cpp/chrono/weekday
public:
    MACRO_CREATE_AND_GETORMNAME(t0036_rythm)
    t0036_rythm():YACBaseObject(Rights::RN_everybody)
    {
        setrepeat_every_months(0);
        setrepeat_every_days(0);
        setxth_day_from_month_beginn(-1);
        setxth_day_from_month_end(-1);
        setspecial_day_of_week(-1);

        MACRO_ADD_PROPERTY(app_id);
        MACRO_ADD_PROPERTY(rythm_name);
        MACRO_ADD_PROPERTY(default_rythm);
        MACRO_ADD_PROPERTY(repeat_every_months);
        MACRO_ADD_PROPERTY(repeat_every_days);
        MACRO_ADD_PROPERTY(xth_day_from_month_beginn);
        MACRO_ADD_PROPERTY(xth_day_from_month_end);
        MACRO_ADD_PROPERTY(special_day_of_week);
    }

    std::chrono::sys_days next(const std::chrono::sys_days &current);
};

#endif // T__36_RYTHM_H
