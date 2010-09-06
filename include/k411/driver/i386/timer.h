#ifndef HAL_TIMER_H
// Copied from dux/metodo @ http://github.com/RockerMONO/dux
#define HAL_TIMER_H

extern void HalTimerHandler(struct regs *r);
extern unsigned int HalGetTicks();
extern void HalTimerInit();

#endif /* end of include guard: HAL_TIMER_H */
