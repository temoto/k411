// k411 kernel/main.c
// Most code copied from dux/metodo @ http://github.com/RockerMONO/dux
#include <k411.h>
#include <k411/modules.h>
#include <k411/tests.h>
#include <string.h>


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

			if (strncmp((char*)module->string, (char*)"/Drivers/", 9) == 0) {
				printf("Loading driver: %s\n", (char*)module->string);
				//LoadExe((void*)module->mod_start);
				//while(1){}
			}
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
		// Print info about current memory map
/*      printf("mmap:\n\
		size: %i\n\
		base_addr_low: 0x%x\n\
		base_addr_high: 0x%x\n\
		length_low: %i\n\
		length_high: %i\n\
		type: %i\n",*/
		printf(" %8x | %8x | %8x | %8x | %8x | %8x\n",
		mmap->size, mmap->base_addr_low, mmap->base_addr_high,
		mmap->length_low, mmap->length_high, mmap->type);
	}

//    userland = GetModule("/System/userland.exe");

	/* Initialize pseudo-user mode */
/*
	if (userland != NULL) {
		printf("Loading userland...\n");
		//HalSwitchToUserMode();
		LoadUserland(userland);
		printf("\nWhy yes, that is a black hole that flew out of userland...\n(Userland exited unexpectedly)\n");
	} else {
*/
		//panic("No userland");
		printf("No userland\n");
		HalBreak();
		//KernDebug();
		//KrnlEasyStop(STOP_NO_USERLAND);
//    }

	while (1) {
		__asm ("nop");
	}
}
