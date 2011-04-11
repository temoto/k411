#ifndef HAL_TIMER_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define HAL_TIMER_H

#define PIT_CLOCK_RATE 1193180
#define PIT_MAX_TIMER_INTERVAL ((uint64_t)0xffff * 1000000 / PIT_CLOCK_RATE)

enum TimerMode {
	INVALID = 0,
	TIMER_ONESHOT,
	TIMER_REPEATING,
};


void HalTimerHandler(struct regs *r);
unsigned int HalGetTicks();
void HalTimerInit();
void HalTimerSet(const uint32_t timeout, const enum TimerMode mode);

#endif /* end of include guard: HAL_TIMER_H */
