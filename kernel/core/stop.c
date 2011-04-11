// Copied from dux/metodo @ http://github.com/duckinator/dux
#include <stdint.h>

#include <k411.h>
#include <k411/stop.h>
 
static int in_stop = 0;


void KernelStop(uint32_t error, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4)
{
	if (in_stop) {
		/* Its recursive! */
		HalShutdown();
	}
	in_stop = 1;

	DisplayInit();
	DisplaySetAttr(0x4f);
	DisplayClear();

	DisplayString("An error has occured and Dux has been shutdown to prevent damage.\n\n");

	printf("STOP: %x (%x, %x, %x, %x)\n", error, arg1, arg2, arg3, arg4);
 
#ifdef DEBUG
	DisplayString("BREAK\n");
	HalBreak();
#else
	HalShutdown();
#endif
}
