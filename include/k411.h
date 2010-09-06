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

extern void monitor_clear();
extern void monitor_switch_pages(unsigned int a, unsigned int b);
extern unsigned int monitor_get_cursor_x();
extern unsigned int monitor_get_cursor_y();
extern void monitor_set_cursor(unsigned int x, unsigned int y);

multiboot_info_t *mbd;
memory_map_t *mmaps[100];

#endif /* end of include guard: K411_H */
