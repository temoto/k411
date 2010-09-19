// Copied from dux/metodo @ http://github.com/RockerMONO/dux
#include <k411.h>


inline void HalDisableInterrupts_(void)
{
	__asm __volatile__ ("cli");
}

inline unsigned long HalDisableInterrupts(void)
{
	unsigned long flags = HalGetCpuFlags();
	__asm volatile ("cli");
	return flags;
}

inline void HalEnableInterrupts(void)
{
	__asm __volatile__ ("sti");
}

inline void HalDisableNMI(void)
{
	HalOutPort(0x70, HalInPort(0x70) | 0x80);
}

inline void HalEnableNMI(void)
{
	HalOutPort(0x70, HalInPort(0x70) & 0x7f);
}


// Copied from Linux 2.6 @ http://kernel.org/
inline unsigned long HalGetCpuFlags(void)
{
	unsigned long flags;

	/*
	 * "=rm" is safe here, because "pop" adjusts the stack before
	 * it evaluates its effective address -- this is part of the
	 * documented behavior of the "pop" instruction.
	 */
	__asm volatile("pushf ; pop %0"
	               : "=rm" (flags)
	               : /* no input */
	               : "memory");

	return flags;
}

inline void HalSetCpuFlags(unsigned long flags)
{
	__asm volatile("push %0 ; popf"
	               : /* no output */
	               : "g" (flags)
	               : "memory", "cc");
}
