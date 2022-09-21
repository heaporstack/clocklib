#include "interface.h"
#include "timestamp.h"
#include "datetime.h"

byte main()
{
    Timestamp* timestamp = create_timestamp(1663266156);
    Datetime* datetime = create_datetime(timestamp->seconds);
    byte* str_datetime = stringify_datetime(datetime);
    byte* str_timestamp = stringify_timestamp(timestamp);

    console_out("Seconds: %ss\n", str_timestamp);
    console_out("Date format: %s\n", str_datetime);

    delete_timestamp(timestamp);
    delete_datetime(datetime);
    deallocate(str_datetime);
    deallocate(str_timestamp);
    
    return 0;
}
