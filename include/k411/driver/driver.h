#ifndef DRIVER_H
// Copied from dux/metodo @ http://github.com/RockerMONO/dux
#define DRIVER_H

#include <k411.h>

#define DRIVER_INIT(func) void _start(void) { ##func (); }

#endif
