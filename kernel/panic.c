// Copied from dux/metodo @ http://github.com/duckinator/dux
#include <k411.h>
#include <system.h>

unsigned int stack;
static int in_panic = 0;

char *stop_table[7] = {
	(char*)0x01, "ASSERTION_FAILED",
	(char*)STOP_BAD_MULTIBOOT_SIGNATURE, "NO_MULTIBOOT",
	(char*)0x10, "USER_INITIALIZED",
	(char*)0x0
};

noreturn _panic(char *text, const char *function, const char *filename, int line)
{
	if (in_panic) {
		/* Something is causing a recursive panic, so
		 * just kill the machine. */
		HalShutdown();
	}
	in_panic = 1;
 
	DisplayInit();
	DisplaySetAttr(0x4f);
	DisplayClear();
	printf("\n**** UDUDD ***\n\n%s\n\n", text);
	printf("Function: %s\nFile: %s\nLine: %d\n", function, filename, line);
	StackDump();

	HalShutdown();
}
 
void PanicDumpHex(unsigned int *stack)
{
	unsigned int orig_stack = (unsigned int) stack;
	printf("\nBecause I stack-traced it!\n");
	while ((unsigned int) stack < ((orig_stack+0x1000) & (unsigned int)(~(0x1000-1)))) {
		printf("0x%x: 0x%x\n", stack, *stack);
		if ( *stack == 0x0 )
			break;
		stack++;
	}
}

char *StopGetMsg(int error)
{
	int i;
	int index;
 
	/* Loop through the table, stopping at every other entry to see if it
	 * matches. If so, record it. */
	for (i = 0; stop_table[i] != 0x0; i+=2) {
		if ((int)stop_table[i] == error) {
			index = i;
			break;
		}
	}
 
	return (char*)stop_table[index+1];
}

noreturn Stop(int error, int argc, ...)
{
	va_list ap;
	int i;
	unsigned int arg;
	char *function, *file, *code;
	int line;

	if (in_panic) {
		/* Something is causing a recursive stop, so
		 * just kill the machine. */
		HalShutdown();
	}
	in_panic = 1;

	DisplayInit();
	DisplaySetAttr(0x4f);
	DisplayClear();

	printf(STOP_MSG);
	printf("%s\n\n", StopGetMsg(error));

	va_start(ap, argc);

	if ((error == 0x01) && (argc >= 4)) { // Assertion failed
		function = (char*)va_arg(ap, const char*);
		file = (char*)va_arg(ap, const char*);
		line = va_arg(ap, int);
		code = (char*)va_arg(ap, const char*);
		printf("Assertion failed in %s at %s:%d\n\n", function, file, line);
		printf("Failed assertion: %s\n\n", code);
		argc -= 4;
	}

	printf("STOP: 0x%x (", error);

	/* Print all the arguments. */
	for (i = 0; i < argc; i++) {
		arg = va_arg(ap, unsigned int);
		printf("0x%x, ", arg);
	}

	/* \x08 is backspace, so it doesn't have an extra ", " at the end. */
	if (argc != 0)
		printf("\x08\x08)\n\n");
	else
		printf(")\n\n");

	va_end(ap);

	printf("Stack Dump:\n\n");

	StackDumpStop();

	HalShutdown();
}

void AssertDoWork(const char *function, const char *file, int line, const char *code)
{
	Stop(0x01, 0x4, function, file, line, code);
}

void StackDumpStop(void)
{
	struct stack_frame *frame;
 
	__asm volatile ("movl %%ebp, %0" : "=rm" (frame));
 
	while ((unsigned int)frame < stack) {
		printf("addr: 0x%x, frame: 0x%x\n", frame->addr, frame);
		frame = frame->next;
	}
}
