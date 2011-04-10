#include <k411.h>
#include <k411/core/scheduler.h>
#include <k411/core/task.h>
#include <string.h>


bool kspawn_fun(KThreadFun func) {
	SchedulerProcess proc;
	ProcessInit(&proc, "kernel task", func, 8 * 1024);

	processes[number_of_processes] = proc;
	number_of_processes += 1;

	return true;
}


int ProcessInit(SchedulerProcess *proc, const char *name, KThreadFun entry_point, size_t stack_size) {
	assert(NULL != proc);

	memset(proc, 0, sizeof(SchedulerProcess));

	proc->state = PROCESS_SUSPENDED;

	proc->stack = kmalloc(stack_size);
	if (!proc->stack) {
		return 1;
	}
	proc->stack_size = stack_size;

	proc->entry_point = entry_point;
	ProcessSetName(proc, name);

	HalProcessInit(proc);

	return 0;
}


void ProcessResume(SchedulerProcess *proc) {
	proc->state = PROCESS_RUNNING;
	CoSchedulerHandler();
}


void ProcessSuspend(SchedulerProcess *proc) {
	proc->state = PROCESS_SUSPENDED;
	CoSchedulerHandler();
}


void ProcessExit(SchedulerProcess *proc) {
	proc->state = PROCESS_FINISHED;
	CoSchedulerHandler();
}


/* Sets process name.
 * Returns boolean flag whether name was truncated to PROCESS_NAME_LENGTH.
 */
bool ProcessSetName(SchedulerProcess* proc, const char *name) {
	assert(NULL != proc);

	size_t n = strlcpy(proc->name, name, PROCESS_NAME_LENGTH);

	return n > PROCESS_NAME_LENGTH;
}
