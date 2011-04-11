#ifndef PANIC_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define PANIC_H

#define STOP_MSG "A problem has been detected and K411 has been shut down to prevent damage\nto your computer.\n\n"

#define va_start(v,l) __builtin_va_start(v,l)
#define va_arg(v,l)   __builtin_va_arg(v,l)
#define va_end(v)     __builtin_va_end(v)
#define va_copy(d,s)  __builtin_va_copy(d,s)
//typedef __builtin_va_list va_list;

struct stack_frame {
	struct stack_frame *next;
	void *addr; 
};

void PanicDumpHex(unsigned int *stack);
char *StopGetMsg(int error);
noreturn stop(int error, int argc, ...);
void StackDumpStop(void);
void StackDump(void);
void DumpRegisters(void);

void PanicSetupStopTable();

/* Assert */
void AssertDoWork(const char *function, const char *file, int line, const char *code);
#define assert(a) if (!(a)) AssertDoWork(__FUNCTION__, __FILE__, __LINE__, #a)

/* Panic */
noreturn _panic(char *text, const char *function, const char *filename, int line);
#define panic(message) _panic(message, __FUNCTION__, __FILE__, __LINE__)

#endif /* end of include guard: PANIC_H */
