// Copied from dux/metodo @ http://github.com/RockerMONO/dux
#include <k411.h>


inline void HalDisableInterrupts(void)
{
	__asm__ __volatile__ ("cli");
}

inline void HalEnableInterrupts(void)
{
	__asm__ __volatile__ ("sti");
}

inline void HalDisableNMI(void)
{
	HalOutPort(0x70, HalInPort(0x70) | 0x80);
}

inline void HalEnableNMI(void)
{
	HalOutPort(0x70, HalInPort(0x70) & 0x7f);
}
