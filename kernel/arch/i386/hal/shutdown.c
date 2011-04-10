// Copied from dux/metodo @ http://github.com/duckinator/dux
#include <k411.h>

void HalBreak(void)
{
	__asm volatile ("int $3");
}

noreturn HalShutdown(void)
{
	while (1) {
		__asm volatile ("cli");
		__asm volatile ("hlt");
	}
}

// FIXME: Fix HalReboot(), it causes a SIMD Floating Point Exception
noreturn HalReboot(void)
{
	unsigned char good = 0x02;
	HalDisableInterrupts();
	__asm volatile ("int $0x13");

	while ((good & 0x02) != 0) {
		good = HalInPort(0x64);
	}
	HalOutPort(0x64, 0xFE);

	HalShutdown();
}
