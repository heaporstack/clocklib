#include "interface.h"
#include "timestamp.h"

Timestamp* create_timestamp(u64 seconds)
{
    Timestamp* timestamp = allocate(sizeof(Timestamp));
    timestamp->seconds = seconds;
    return timestamp;
}

void delete_timestamp(Timestamp* timestamp)
{
    deallocate(timestamp);
}

u8* stringify_timestamp(const Timestamp* timestamp)
{
    u64 digits = 0;
    u64 seconds = timestamp->seconds;
    while (seconds > 0)
    {
        seconds /= 10;
        ++digits;
    }
    u8* string = allocate(digits);
    string_format(string, "%llu", timestamp->seconds);
    return string;
}
