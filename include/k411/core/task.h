#ifndef K411_CORE_TASK
#define K411_CORE_TASK

typedef void (* KThreadFun)();

#ifdef ARCH_i386
  #include <k411/hal/i386/proc_regs.h>
#endif

typedef struct SchedulerProcess_s {
	int used;
	struct proc_regs registers;

	void *stack; // base of stack
	void *esp;   // saved stack base so it can be destroyed when process is destroyed
} SchedulerProcess;


bool kspawn_fun(KThreadFun func);

#endif // ifndef K411_CORE_TASK
