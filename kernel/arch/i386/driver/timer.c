// Copied from dux/metodo @ http://github.com/duckinator/dux
#include <config.h>
#include <k411/driver/driver.h>
#include <k411/driver/i386/timer.h>
#include <k411/core/scheduler.h>


static unsigned int ticks = 0;


void HalTimerHandler(UNUSED struct regs *r)
{
	// Increment ticks
	ticks++;

	// Scheduler
	if ( IsSchedulerEnabled() ) {
		SchedulerHandler();
	}
}

unsigned int HalGetTicks()
{
	return ticks;
}

void HalTimerInit()
{
	HalIrqHandlerInstall(0, (void*)HalTimerHandler);
	HalTimerSet(DEFAULT_TIMER_INTERVAL, TIMER_REPEATING);
}


/* Set timer.
 *
 * @param timeout in microseconds. Min value is 1, max value is PIT_MAX_TIMER_INTERVAL.
 *
 * Copied from http://git.newos.org/?p=newos.git;a=blob;f=kernel/arch/i386/arch_timer.c;h=f09bdb54f9ca83cf73e7a5b8f01b4c9311623a33;hb=master
 */
void HalTimerSet(const uint32_t timeout, const enum TimerMode mode)
{
	assert(timeout > 0);
	assert(timeout < PIT_MAX_TIMER_INTERVAL);

	uint16_t next_ticks = timeout * PIT_CLOCK_RATE / 1000000;

	if (mode == TIMER_ONESHOT) {
		HalOutPort(0x43, 0x30); // mode 0 (countdown then stop), load LSB then MSB
		HalOutPort(0x40, next_ticks & 0xff);
		HalOutPort(0x40, (next_ticks >> 8) & 0xff);
	} else if (mode == TIMER_REPEATING) {
		HalOutPort(0x43, 0x36); // mode 3 (square wave generator), load LSB then MSB
		HalOutPort(0x40, next_ticks & 0xff);
		HalOutPort(0x40, (next_ticks >> 8) & 0xff);
	}
}
