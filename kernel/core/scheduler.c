// Copied from dux/metodo @ http://github.com/duckinator/dux
#include <k411.h>
#include <k411/core/scheduler.h>
#include <k411/hal/i386/scheduler.h>


SchedulerProcess *processes;
int32_t number_of_processes = 0;
SchedulerProcess *idle_process;

static int32_t current_process_id = 0;
static uint8_t scheduler_firstrun = 1;
static int scheduler_enabled = 0;


void SchedulerEnable() { scheduler_enabled = 1; }
void SchedulerDisable() { scheduler_enabled = 0; }
int IsSchedulerEnabled() { return scheduler_enabled; }


void SchedulerHandler(void)
{
	unsigned long flags = HalDisableInterrupts();

	if (scheduler_firstrun) {
		processes = kmalloc(sizeof(SchedulerProcess) * 1024);
		memset(processes, 0, sizeof(SchedulerProcess) * 1024);

		scheduler_firstrun = 0;
	}

	SchedulerProcess *old_proc = SchedulerCurProcess(),
	                 *new_proc;
	int32_t new_proc_id = SchedulerNextProcess();
	printf("|Switch from %i to %i.\n", current_process_id, new_proc_id);

	if (new_proc_id != current_process_id) {
		current_process_id = new_proc_id;
		new_proc = &(processes[new_proc_id]);
		HalSwitchContext(old_proc, new_proc);
	}

	// to restore IF flag
	HalSetCpuFlags(flags);
}

int32_t SchedulerCurProcessId(void)
{
	return current_process_id;
}

SchedulerProcess *SchedulerCurProcess(void)
{
	return &(processes[current_process_id]);
}

int32_t SchedulerNextProcessLoop(int32_t begin, int32_t end)
{
	int32_t i;

	if (end == -1) {
		end = number_of_processes;
	}

	if (begin == end) {
		if(end > number_of_processes) {
			end = number_of_processes;
		} else {
			begin = 0;
			end = number_of_processes;
		}
	}

	// Try processes with ids from begin to end
	for (i = begin; i < end; i++) {
		if (processes[i].used) {
			return i;
		}
	}

	// If we are past the last process in the group, return -1
	return -1;
}

int32_t SchedulerNextProcess(void)
{
	int32_t result;
	int32_t last_process = current_process_id;

	// Try processes current_process_id -> (number_of_processes-1)
	result = SchedulerNextProcessLoop(last_process+1, -1);

	// If result == -1, try again from 0 -> last_process
	if(result == -1) {
		result = SchedulerNextProcessLoop(0, last_process);
	}

	// If result is still -1, either something exploded or there's no processes
	if(result == -1) {
		printf("\n\nNo processes");
	}

	return result;
}
