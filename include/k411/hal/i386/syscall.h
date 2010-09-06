#ifndef HAL_SYSCALL_H
// Copied from dux/metodo @ http://github.com/RockerMONO/dux
#define HAL_SYSCALL_H

#include <k411/hal/i386/isr.h>

extern void HalSyscallHandler(struct regs *r);
extern void HalIsrSyscall(void);

void HalInitializeSyscalls();

#endif /* end of include guard: HAL_SYSCALL_H */
