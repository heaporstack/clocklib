#ifndef CLOCKLIB_DATETIME
#define CLOCKLIB_DATETIME

#include "types.h"
#include "timestamp.h"

typedef struct
{
    large year;
    byte month;
    byte day;
    byte hour;
    byte minute;
    byte second;
} Datetime;

Datetime* create_datetime_with_utc(large, byte);
#define create_datetime(seconds) create_datetime_with_utc(seconds, 0)
void delete_datetime(Datetime*);
byte* stringify_datetime(const Datetime*);

#endif
