#ifndef HAL_SCHEDULER_H
// Copied from dux/metodo @ http://github.com/RockerMONO/dux
#define HAL_SCHEDULER_H

#include <k411/core/task.h>


void HalSchedulerEnable();
void HalSchedulerDisable();
int HalIsSchedulerEnabled();
/*
 * Defined in core/scheduler.h:
 * void HalSchedulerRunProcess(SchedulerProcess proc);
 */

#endif /* end of include guard: HAL_SCHEDULER_H */
