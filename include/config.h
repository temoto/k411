#ifndef CONFIG_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define CONFIG_H

/* The following line, if defined, has printf() and friends use memory management.
 * If commented, they will not use memory management at all
 */
//#define PRINTF_USE_MM

/* Interrupt for syscalls:
 *   default is 0xFF
 *   used to use 0x80 (got the idea from Linux)
 * kernel/arch/i386/hal/exceptions.asm
 * This must also be changed in HalIsrSyscall - line 15 in
 */
#define IA32_SYSCALL_INTERRUPT 0xFF


// Default console color attributes
#define CONSOLE_BG_COLOR 0x0
#define CONSOLE_FG_COLOR 0x7


// Initial timer frequency. In microseconds.
#define DEFAULT_TIMER_INTERVAL 1000

#endif /* end of include guard: CONFIG_H */
