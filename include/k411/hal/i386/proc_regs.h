#ifndef HAL_PROC_REGS_H
#define HAL_PROC_REGS_H

struct proc_regs {
	unsigned int gs, fs, es, ds;
	unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
	unsigned int int_no, err_code;
	unsigned int eip, cs, eflags, useresp, ss;
};

#endif /* ifndef HAL_PROC_REGS_H */
