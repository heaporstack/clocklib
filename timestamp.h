#ifndef clocklib_timestamp
#define clocklib_timestamp

#include "types.h"

typedef struct
{
    u64 seconds;
} Timestamp;

Timestamp* create_timestamp(u64);
void delete_timestamp(Timestamp*);
u8* stringify_timestamp(const Timestamp*);

#endif
