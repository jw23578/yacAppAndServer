#ifndef T__36_RYTHM_H
#define T__36_RYTHM_H

#include "yacbaseobject.h"
#include <chrono>

class t0036_rythm : public YACBaseObject
{
    Q_OBJECT

    MACRO_INT_PROPERTY(repeat_every_months)
    MACRO_INT_PROPERTY(repeat_every_days)
    MACRO_INT_PROPERTY(xth_day_from_month_beginn) // -1 inactive
    MACRO_INT_PROPERTY(xth_day_from_month_end) // -1 inactive
    MACRO_INT_PROPERTY(special_day_of_week) // 0 = Sunday to 6 = Saturday, -1 inactive https://en.cppreference.com/w/cpp/chrono/weekday
public:
    MACRO_CREATE_AND_GETORMNAME(t0036_rythm)
    t0036_rythm():YACBaseObject(Rights::RN_everybody)
    {
        m_repeat_every_months = 0;
        m_repeat_every_days = 0;
        m_xth_day_from_month_beginn = -1;
        m_xth_day_from_month_end = -1;
        m_special_day_of_week = -1;
        MACRO_ADD_PROPERTY(repeat_every_months);
        MACRO_ADD_PROPERTY(repeat_every_days);
        MACRO_ADD_PROPERTY(xth_day_from_month_beginn);
        MACRO_ADD_PROPERTY(xth_day_from_month_end);
        MACRO_ADD_PROPERTY(special_day_of_week);
    }

    std::chrono::sys_days next(const std::chrono::sys_days &current);
};

#endif // T__36_RYTHM_H
