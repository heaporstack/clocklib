#include "interface.h"
#include "datetime.h"

Datetime* create_datetime_with_utc(large seconds, byte utc)
{
    Datetime* datetime = allocate(sizeof(Datetime));
    datetime->second = 0 + seconds % 60;
    seconds /= 60;
    datetime->minute = 0 + seconds % 60;
    seconds /= 60;
    datetime->hour = utc + seconds % 24;
    seconds /= 24;

    large year = 1970;
    byte month = 0;
    byte days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (seconds > days_per_month[month])
    {
        if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
        {
            days_per_month[1] = 29;
        }
        else
        {
            days_per_month[1] = 28;
        }
        if (month == 12)
        {
            month = 0;
            ++year;
        }
        seconds -= days_per_month[month];
        ++month;
    }
    datetime->day = seconds + 1;
    datetime->month = month + 1;
    datetime->year = year;

    return datetime;
}

void delete_datetime(Datetime* datetime)
{
    deallocate(datetime);
}

byte* stringify_datetime(const Datetime* datetime)
{
    byte year[6];
    string_format(year, "%llu", datetime->year);

    byte month[3];
    if (datetime->month < 10) string_format(month, "0%u" , datetime->month);
    else string_format(month, "%u" , datetime->month);

    byte day[3];
    if (datetime->day < 10) string_format(day, "0%u", datetime->day);
    else string_format(day, "%u", datetime->day);

    byte hour[3];
    if (datetime->hour < 10) string_format(hour, "0%u", datetime->hour);
    else string_format(hour, "%u", datetime->hour);

    byte minute[3];
    if (datetime->minute < 10) string_format(minute, "0%u", datetime->minute);
    else string_format(minute, "%u", datetime->minute);

    byte second[3];
    if (datetime->second < 10) string_format(second, "0%u", datetime->second);
    else string_format(second, "%u", datetime->second);

    byte* str = allocate(30);
    string_format(str, "%s/%s/%s %s:%s:%s", day, month, year, hour, minute, second);
    return str;
}
