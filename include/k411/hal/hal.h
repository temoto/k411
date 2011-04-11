#ifndef HAL_H
#define HAL_H

#include <k411/hal/mm.h>

#ifdef ARCH_i386
	#include <k411/hal/i386.h>
#endif

// Common
void HalPreInit(void);
void HalInit(void);
void HalBreak(void);
noreturn HalShutdown(void);
void HalReboot(void);


// Interrupts
void HalDisableInterrupts_(void);
unsigned long HalDisableInterrupts(void);
void HalEnableInterrupts(void);
void HalDisableNMI(void);
void HalEnableNMI(void);


// CPU
unsigned long HalGetCpuFlags(void);
void HalSetCpuFlags(unsigned long);
void HalHalt(void);
void HalPause(void);


// Tasks
#include <k411/core/task.h>
void HalSwitchContext(SchedulerProcess *prev, SchedulerProcess *next);
void HalSwitchToUserMode();

#endif /* end of include guard: HAL_H */
