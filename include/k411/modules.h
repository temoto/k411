#ifndef MISC_MODULES_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define MISC_MODULES_H

#include <k411.h>
#include <string.h>

// Kernel modules passed via grub

typedef struct Module_s {
	char *name;
	void *exe;
} Module;

Module *modules;

void *GetModule(const char *name);

#endif /* end of include guard: MISC_MODULES_H */
