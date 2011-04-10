#ifndef CORE_SCHEDULER_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define CORE_SCHEDULER_H

#include <stdint.h>


extern SchedulerProcess *processes;
extern uint32_t number_of_processes;
extern SchedulerProcess *idle_process;


void SchedulerEnable();
void SchedulerDisable();
int IsSchedulerEnabled();

void SchedulerHandler(void);
SchedulerProcess *SchedulerCurProcess(void);
int32_t SchedulerCurProcessId(void);
int32_t SchedulerNumProcesses(void);
int32_t SchedulerNextProcessLoop(int32_t begin, int32_t end);
int32_t SchedulerNextProcess(void);
void SchedulerSetNumProcesses(int32_t num);

#endif /* end of include guard: CORE_SCHEDULER_H */
