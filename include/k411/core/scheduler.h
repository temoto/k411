#ifndef CORE_SCHEDULER_H
// Copied from dux/metodo @ http://github.com/RockerMONO/dux
#define CORE_SCHEDULER_H

#include <stdint.h>

void CoSchedulerHandler(void);
SchedulerProcess *CoSchedulerCurProcess(void);
int32_t CoSchedulerCurProcessId(void);
int32_t CoSchedulerNumProcesses(void);
int32_t CoSchedulerNextProcessLoop(int32_t begin, int32_t end);
int32_t CoSchedulerNextProcess(void);
void CoSchedulerSetNumProcesses(int32_t num);

#endif /* end of include guard: CORE_SCHEDULER_H */
