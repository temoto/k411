#ifndef K411_CORE_TASK
#define K411_CORE_TASK

typedef void (* KThreadFun)();


enum ProcessState {
	INVALID_STATE = 0,
	PROCESS_SUSPENDED,
	PROCESS_RUNNING,
	PROCESS_FINISHED,
};

#define PROCESS_NAME_LENGTH 32

typedef struct SchedulerProcess_s {
	enum ProcessState state;

	void *stack; // base of stack
	void *esp;   // saved stack base so it can be destroyed when process is destroyed
	size_t stack_size;

	KThreadFun entry_point;

	char name[PROCESS_NAME_LENGTH];
} SchedulerProcess;


bool kspawn_fun(KThreadFun func);

int  ProcessInit(SchedulerProcess *proc, const char *name, KThreadFun entry_point, size_t stack_size);
void ProcessResume(SchedulerProcess *proc);
void ProcessSuspend(SchedulerProcess *proc);
void ProcessExit(SchedulerProcess *proc);
bool ProcessSetName(SchedulerProcess* proc, const char *name);


void HalProcessInit(SchedulerProcess *proc);

#endif // ifndef K411_CORE_TASK
