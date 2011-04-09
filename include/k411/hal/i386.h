#ifndef HAL_I386_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define HAL_I386_H

#include <k411/hal/i386/idt.h>

/* Interrupts */
void HalDisableInterrupts_(void);
unsigned long HalDisableInterrupts(void);
void HalEnableInterrupts(void);

void HalDisableNMI(void);
void HalEnableNMI(void);

unsigned long HalGetCpuFlags();
void HalSetCpuFlags(unsigned long);

#include <k411/hal/i386/exceptions.h>
#include <k411/hal/i386/ports.h>
#include <k411/hal/i386/isr.h>
#include <k411/hal/i386/syscall.h>

#include <k411/driver/i386/timer.h>
#include <k411/driver/i386/keyboard.h>

#define HalHalt() __asm __volatile__ ("hlt")
// TODO: Check if PAUSE is available, use NOP if not.
#define HalPause() __asm __volatile__ ("pause")

#endif /* end of include guard: HAL_I386_H */
