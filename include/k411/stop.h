#ifndef STOP_H
// Copied from dux/metodo @ http://github.com/RockerMONO/dux
#define STOP_H

#include <stdint.h>

#define STOP_UNKNOWN 0x1
#define STOP_BAD_MULTIBOOT_SIGNATURE 0x2
#define STOP_NO_USERLAND 0x3

void kstop(uint32_t error, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4);
#define KrnlEasyStop(error) KrnlStop(error, 0, 0, 0, 0);

#endif /* end of include guard: STOP_H */