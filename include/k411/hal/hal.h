#ifndef HAL_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define HAL_H

#include <k411/hal/mm.h>

#ifdef ARCH_i386
	#include <k411/hal/i386.h>
#endif

void HalPreInit(void);
void HalInit(void);
void HalBreak(void);
void HalShutdown(void);
void HalReboot(void);

#endif /* end of include guard: HAL_H */
