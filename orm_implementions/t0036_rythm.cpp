#include "t0036_rythm.h"

std::chrono::sys_days t0036_rythm::next(const std::chrono::sys_days &current)
{
    std::chrono::year_month_day ymd(current);
    ymd += std::chrono::months(repeat_every_months());
    std::chrono::sys_days result(ymd);
    result += std::chrono::days(repeat_every_days());
    if (xth_day_from_month_beginn() != -1)
    {
        ymd = result;
        if (ymd.day() >= std::chrono::day(xth_day_from_month_beginn()))
        {
            ymd += std::chrono::months(1);
        }
        ymd = std::chrono::year_month_day(ymd.year(), ymd.month(), std::chrono::day(xth_day_from_month_beginn()));
        if (special_day_of_week() != -1)
        {
            while (std::chrono::weekday(ymd) != std::chrono::weekday(special_day_of_week()))
            {
                std::chrono::sys_days sd(ymd);
                sd += std::chrono::days(1);
                ymd = sd;
            }
        }
        result = ymd;
    }
    return result;
}
