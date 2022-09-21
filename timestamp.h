#ifndef CLOCKLIB_TIMESTAMP
#define CLOCKLIB_TIMESTAMP

#include "types.h"

typedef struct
{
    large seconds;
} Timestamp;

Timestamp* create_timestamp(large);
void delete_timestamp(Timestamp*);
byte* stringify_timestamp(const Timestamp*);

#endif
