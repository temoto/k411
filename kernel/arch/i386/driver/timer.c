// Copied from dux/metodo @ http://github.com/duckinator/dux
#include <k411/driver/driver.h>
#include <k411/driver/i386/timer.h>
#include <k411/core/scheduler.h>
#include <k411/hal/i386/scheduler.h>


unsigned int ticks = 0;

void HalTimerHandler(UNUSED struct regs *r)
{
	// Increment ticks
	ticks++;

	// Scheduler
	if ( HalIsSchedulerEnabled() ) {
		CoSchedulerHandler();
	}
}

unsigned int HalGetTicks()
{
	return ticks;
}

void HalTimerInit()
{
	HalIrqHandler_Install(0, (void*)HalTimerHandler);
}
