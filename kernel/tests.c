// Copied from dux/metodo @ http://github.com/duckinator/dux
#include <k411/tests.h>

extern unsigned int start;
extern unsigned int end;

void SystemTests()
{
	MemorySizeTest();
	MMTest();
	KernelSizeTest();

	// Very very slow in qemu.
	//UsedFrameTest();
}

void KernelSizeTest()
{
	printf("Kernel size is approximately %i bytes (start: 0x%08x, end: 0x%08x)\n", &end-&start, &start, &end);
}

void MemorySizeTest()
{
	unsigned long int bytes = mbd->mem_upper*1024;
	char *ext = kmalloc(sizeof(char) * 6);
	unsigned long int last;
	int exp = 0;
	while(1) {
		if ( bytes >= 1 ) {
			exp += 3;
			last = bytes;
			bytes /= 1024;
		} else {
			bytes = last;
			exp -= 3;
			break;
		}
	}

	switch(exp) {
	case 0:
		strcpy(ext, (char*)" bytes");
		break;
	case 3:
		strcpy(ext, (char*)"KB");
		break;
	case 6:
		strcpy(ext, (char*)"MB");
		break;
	case 9:
		strcpy(ext, (char*)"GB");
		break;
	}
	printf("We have %d%s of RAM\n", bytes, ext);
	free(ext);
}

void MMTest()
{
	printf("Beginning memory management test:\n");
	printf("\tFirst free frame:  %i\n", FirstFrame());
	printf("\tAllocating frame at %i\n", FirstFrame());
	SetFrame(FirstFrame());
	printf("\tFirst free frame is now %i\n", FirstFrame());
	printf("Finished memory management test\n\n");
}

void UsedFrameTest()
{
	for (unsigned int i = 0; i < end_memory; i += 0x1000) {
		if (TestFrame(i)) {
			printf("Frame %u (%u-%u) is used.\n", i, i, i+0x0111);
		}
	}
}
