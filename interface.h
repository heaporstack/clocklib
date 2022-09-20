/**
 * This file is an interface for clocklib.
 * The purpose of this interface is to provide an abstraction
 * of the system architecture and operating system.
 * As a consequence the only things to change if you want to
 * implement this program on a different operating system is to
 * change functions names and signatures enumerated here.
 * 
 * @author Nathan Marye
 */

#ifndef clocklib_x86_64_linux_interface
#define clocklib_x86_64_linux_interface

#include "types.h"
#include "stdio.h"

#define console_out(args...) printf(args)
#define console_error(args...) fprintf(stderr, args)
#define string_format(buffer, string, args...) sprintf(buffer, string, args)

#include "stdlib.h"

#define allocate malloc
#define deallocate free

#endif
