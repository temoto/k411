#ifndef HAL_SCHEDULER_H
// Copied from dux/metodo @ http://github.com/RockerMONO/dux
#define HAL_SCHEDULER_H

#include <k411/core/task.h>


void HalSchedulerEnable();
void HalSchedulerDisable();
int HalIsSchedulerEnabled();

// not from dux/metodo. From http://git.tkgeisel.com/?p=lk.git;a=blob;f=arch/x86/thread.c;h=f2c2f84eda1a118543e734b4892413be0a40a10d;hb=HEAD
void HalSwitchContext(SchedulerProcess *prev, SchedulerProcess *next);

#endif /* end of include guard: HAL_SCHEDULER_H */
