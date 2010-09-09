#ifndef K411_H
// Copied from dux/metodo @ http://github.com/RockerMONO/dux/blob/master/include/metodo/metodo.h
#define K411_H

#include <system.h>

#include <k411/hal/hal.h>

#include <k411/api/display.h>

#include <k411/init.h>
#include <k411/core/core.h>

#include <multiboot.h>

#include <macros.h>

#include <k411/panic.h>
#include <k411/stop.h>

multiboot_info_t *mbd;
memory_map_t *mmaps[100];

#endif /* end of include guard: K411_H */
