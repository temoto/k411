#ifndef COLPA_DPRINT_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define COLPA_DPRINT_H

#include <system.h>
#include <k411.h>

typedef enum {
	NONE,
	ALL,
	FILESYSTEM,
	MEMORY,
	CONSOLE
} debug_type;
 
static debug_type DEBUG_MODE = NONE;

void dprint(debug_type type, char *str, const char *fmt, ...);
void SetDebugMode(debug_type type);
debug_type GetDebugMode(void);

#endif /* end of include guard: COLPA_DPRINT_H */
