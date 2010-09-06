// Copied from dux/metodo @ http://github.com/RockerMONO/dux
#include <k411.h>
#include <k411/core/scheduler.h>


static int scheduler_enabled = 0;

void HalSchedulerRunProcess(SchedulerProcess *proc)
{
	// unused argument
	proc = proc;

	printf("Switch process %i\n", CoSchedulerCurProcessId());
}

void HalSchedulerEnable()
{
	scheduler_enabled = 1;
}

void HalSchedulerDisable()
{
	scheduler_enabled = 0;
}

int HalIsSchedulerEnabled()
{
	return scheduler_enabled;
}
