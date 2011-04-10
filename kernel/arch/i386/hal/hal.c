// Copied from dux/metodo @ http://github.com/duckinator/dux
#include <k411.h>
#include <k411/core/scheduler.h>


void StartInitializer(const char *name, void (*func)())
{
	printf("Initializing %s...", name);
	func();
	printf("Done.\n");
}

/*
 * HalPreInit is for things that must be enabled before the display drivers. HalInit() is ran after this.
 */
void HalPreInit(void)
{
	HalInitGDT();
}

void HalInit(void)
{
	StartInitializer("IDT", &HalInitIDT);
	StartInitializer("ISRs", &HalIsrInstall);
	StartInitializer("IRQs", &HalIrqInstall);
	StartInitializer("system timer", &HalTimerInit);
	StartInitializer("syscalls", &HalInitializeSyscalls);
	StartInitializer("memory management", &init_mm);
	StartInitializer("keyboard", &HalKeyboardInit);
	StartInitializer("scheduler", &SchedulerEnable);

	printf("Enabling interrupts...");
	HalEnableInterrupts();
	printf("Done.\n");
}
