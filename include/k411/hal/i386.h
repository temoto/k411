#ifndef HAL_I386_H
// Copied from dux/metodo @ http://github.com/RockerMONO/dux
#define HAL_I386_H

#include <k411/hal/i386/idt.h>

/* Interrupts */
void HalDisableInterrupts(void);
void HalEnableInterrupts(void);

void HalDisableNMI(void);
void HalEnableNMI(void);

#include <k411/hal/i386/exceptions.h>
#include <k411/hal/i386/ports.h>
#include <k411/hal/i386/isr.h>
#include <k411/hal/i386/syscall.h>

#include <k411/driver/i386/timer.h>
#include <k411/driver/i386/keyboard.h>

#endif /* end of include guard: HAL_I386_H */