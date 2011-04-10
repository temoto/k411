#include <k411.h>
#include <k411/core/scheduler.h>
#include <k411/core/task.h>


bool kspawn_fun(KThreadFun func) {
	SchedulerProcess proc;
	memset(&proc, 0, sizeof(proc));
	proc.registers.eip = (unsigned int)func;

	processes[number_of_processes] = proc;
	number_of_processes += 1;

	return true;
}
