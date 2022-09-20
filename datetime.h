#ifndef clocklib_datetime
#define clocklib_datetime

#include "types.h"
#include "timestamp.h"

typedef struct
{
    u64 year;
    u8 month;
    u8 day;
    u8 hour;
    u8 minute;
    u8 second;
} Datetime;

Datetime* create_datetime_with_utc(u64, i8);
#define create_datetime(seconds) create_datetime_with_utc(seconds, 0)
void delete_datetime(Datetime*);
u8* stringify_datetime(const Datetime*);

#endif
