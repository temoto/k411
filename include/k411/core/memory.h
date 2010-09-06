#ifndef K411_CORE_MEMORY_H
// Copied from dux/metodo @ http://github.com/RockerMONO/dux
#define K411_CORE_MEMORY_H

void *memcpy(void *dest, void *src, unsigned int count);
extern void *memset(void *dest, unsigned char val, unsigned int count);
unsigned short *memsetw(unsigned short *dest, unsigned short val, unsigned int count);

#endif /* end of include guard: K411_CORE_MEMORY_H */
