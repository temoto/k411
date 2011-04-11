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
noreturn HalShutdown(void);
void HalReboot(void);


// CPU
void HalHalt(void);
void HalPause(void);

#endif /* end of include guard: HAL_H */
