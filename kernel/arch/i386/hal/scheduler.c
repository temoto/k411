// Copied from dux/metodo @ http://github.com/duckinator/dux
#include <k411.h>
#include <k411/core/task.h>


static int scheduler_enabled = 0;


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


// not from dux/metodo. Copied from http://git.tkgeisel.com/?p=lk.git;a=blob;f=arch/x86/thread.c;h=f2c2f84eda1a118543e734b4892413be0a40a10d;hb=HEAD
void HalSwitchContext(SchedulerProcess *prev, SchedulerProcess *next)
{
	__asm volatile (
			"pushl $1f          \n\t"
			"pushf              \n\t"
			"pusha              \n\t"
			"movl %%esp,(%%edx) \n\t"
			"movl %%eax,%%esp   \n\t"
			"popa               \n\t"
			"popf               \n\t"
			"ret                \n\t"
			"1:                 \n\t"
			:
			: "d" (&prev->esp), "a" (next->esp)
			);
}
