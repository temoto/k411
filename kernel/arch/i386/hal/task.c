// Copied from http://git.tkgeisel.com/?p=lk.git;a=blob;f=arch/x86/thread.c;h=f2c2f84eda1a118543e734b4892413be0a40a10d;hb=HEAD
#include <k411.h>
#include <k411/core/scheduler.h>
#include <k411/core/task.h>


struct context_switch_frame {
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t eflags;
	uint32_t eip;
};


void HalSwitchContext(SchedulerProcess *prev, SchedulerProcess *next)
{
	__asm volatile (
			"pushl $1f          \n\t"
			"pushf              \n\t"
			"pusha              \n\t"
			"movl %%esp,(%%edx) \n\t"
			"movl %%eax,%%esp   \n\t"
			"popa               \n\t"
			"popf               \n\t"
			"ret                \n\t"
			"1:                 \n\t"
			:
			: "d" (&prev->esp), "a" (next->esp)
			);
}


static noreturn initial_process_fun(void);
static noreturn initial_process_fun(void)
{
	SchedulerProcess *current_process = CoSchedulerCurProcess();

//	dprintf("initial_thread_func: thread %p calling %p with arg %p\n", current_thread, current_thread->entry, current_thread->arg);
//	dump_thread(current_thread);

	/* exit the implicit critical section we're within */
	//TODO:exit_critical_section();

	current_process->entry_point();

//	dprintf("initial_thread_func: thread %p exiting with %d\n", current_thread, ret);

	ProcessExit(current_process);

	panic("initial_process_fun: passed through ProcessExit.");
}


void HalProcessInit(SchedulerProcess *proc)
{
	// create a default stack frame on the stack
	uintptr_t stack_top = (uintptr_t)proc->stack + proc->stack_size;

	// make sure the top of the stack is 8 byte aligned for EABI compliance
	stack_top = ROUNDDOWN(stack_top, 8);

	struct context_switch_frame *frame = (struct context_switch_frame *)(stack_top);
	frame--;

	// fill it in
	memset(frame, 0, sizeof(*frame));

	frame->eip = (uintptr_t) &initial_process_fun;
	frame->eflags = 0x3002; // IF = 0, NT = 0, IOPL = 3
	//frame->cs = CODE_SELECTOR;
	//frame->fs = DATA_SELECTOR;
	//frame->gs = DATA_SELECTOR;
	//frame->es = DATA_SELECTOR;
	//frame->ds = DATA_SELECTOR;

	// set the stack pointer
	proc->esp = frame;
}
