// k411 kernel/main.c
// Most code copied from dux/metodo @ http://github.com/duckinator/dux
#include <k411.h>
#include <k411/core/scheduler.h>
#include <k411/modules.h>
#include <k411/tests.h>
#include <string.h>


SchedulerProcess bootstrap_process;


void process_1();
void process_2();


noreturn kmain(void *arg, unsigned int magic) {
	if ( magic != 0x2BADB002 ) {
		/* Something went not according to specs. Print an error */
		/* message and halt, but do *not* rely on the multiboot */
		/* data structure. */
		HalInit();
		kstop(STOP_BAD_MULTIBOOT_SIGNATURE, magic, 0, 0, 0);
	}
	mbd = arg;
	memory_map_t *mmap = (memory_map_t*)mbd->mmap_addr;

	HalPreInit(); // HAL-related things that must be started before drivers
	DisplayInit();
	printf("K411 " K411_BUILD_STR " build.\nCompiled at " __TIME__ " " __DATE__ "\n\n");
	HalInit(); // Rest of HAL

	ProcessInit(&bootstrap_process, "Bootstrap", kmain, 8 * 1024);
	bootstrap_process.state = PROCESS_RUNNING;
	assert(0 == number_of_processes);
	processes[number_of_processes] = bootstrap_process;
	number_of_processes += 1;

	/* mbd->flags */
	unsigned int i, len;
	module_t *module;
	int current_module = 0;
	modules = (Module*)kmalloc(sizeof(Module) * 1024);
	if ((mbd->flags >> 3) & 1) {
		module = (module_t*)mbd->mods_addr;
		printf("We have %i modules.\n", mbd->mods_count);
		for (i = 0; i < mbd->mods_count; i++, module++) {
			printf("Module located at 0x%x-0x%x\n", module->mod_start, module->mod_end);
			printf("Module name: %s\n", (char*)module->string);

			len = sizeof(char) * ((unsigned int)strlen((char*)module->string))+1;
			modules[current_module].name = (char*)kmalloc(len);
			memcpy(modules[current_module].name, (char*)(module->string), len);
			modules[current_module].exe = (void*) module->mod_start;
			printf("Found executable %s at 0x%x\n", modules[current_module].name, modules[current_module].exe);
			current_module++;
		}
	}

	SystemTests();

	printf("Memory map:\n");
	printf("\
		  |      base addr      |       length\n\
   size   |   low    |   high   |   low    |   high   |   type\n");
	for (i = 0; mmap < (memory_map_t*)(mbd->mmap_addr + mbd->mmap_length); i++,mmap++) {
		// Store all memory maps in mmaps (see metodo.h)
		mmaps[i] = mmap;
		printf(" %8x | %8x | %8x | %8x | %8x | %8x\n",
		       mmap->size, mmap->base_addr_low, mmap->base_addr_high,
		       mmap->length_low, mmap->length_high, mmap->type);
	}

	kspawn_fun(process_1);
	kspawn_fun(process_2);

	// Make current process the Idle process.
	//CoSchedulerCurProcess()->priority = IDLE_PRIORITY;
	while (true) {
		HalHalt();
		HalPause();
	}
}

void process_1() {
	while (true) {
		printf("A");
		HalHalt();
	}
}

void process_2() {
	while (true) {
		printf("B");
		HalHalt();
	}
}
