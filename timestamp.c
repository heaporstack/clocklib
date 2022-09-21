#include "interface.h"
#include "timestamp.h"

Timestamp* create_timestamp(large seconds)
{
    Timestamp* timestamp = allocate(sizeof(Timestamp));
    timestamp->seconds = seconds;
    return timestamp;
}

void delete_timestamp(Timestamp* timestamp)
{
    deallocate(timestamp);
}

byte* stringify_timestamp(const Timestamp* timestamp)
{
    large digits = 0;
    large seconds = timestamp->seconds;
    while (seconds > 0)
    {
        seconds /= 10;
        ++digits;
    }
    byte* string = allocate(digits);
    string_format(string, "%llu", timestamp->seconds);
    return string;
}
