#ifndef HAL_MM_MEMORY_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define HAL_MM_MEMORY_H

typedef struct {
	unsigned int present : 1;
	unsigned int readwrite : 1;
	unsigned int user : 1;
	unsigned int writethrough : 1;
	unsigned int cachedisable : 1;
	unsigned int accessed : 1;
	unsigned int dirty : 1;
	unsigned int attributeindex : 1;
	unsigned int global : 1;
	unsigned int reserved : 3;
	unsigned int address : 20;
} PageTableEntry;

typedef struct {
	unsigned int present : 1;
	unsigned int readwrite : 1;
	unsigned int user : 1;
	unsigned int writethrough : 1;
	unsigned int cachedisable : 1;
	unsigned int accessed : 1;
	unsigned int available : 1;
	unsigned int pagesize : 1;
	unsigned int global : 1;
	unsigned int reserved : 3;
	unsigned int address : 20;
} PageDirEntry;

#define MALLOC_ALIGN 1

void *kmalloc_int(unsigned int size, unsigned int flags);
void *kmalloc(unsigned int nbytes);
void free(void *ap);

void InitMM();
unsigned int TestFrame(unsigned int addr);
void SetFrame(unsigned int addr);
unsigned int FirstFrame();

unsigned int end_memory;

#endif /* end of include guard: HAL_MM_MEMORY_H */
