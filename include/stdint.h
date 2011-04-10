#ifndef STDINT_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define STDINT_H

typedef unsigned long long  uint64_t;
typedef unsigned int        uint32_t;
typedef unsigned short      uint16_t;
typedef unsigned char       uint8_t;

typedef signed long long    int64_t;
typedef signed int          int32_t;
typedef signed short        int16_t;
typedef signed char         int8_t;


#if __WORDSIZE == 64
typedef long int            intptr_t;
typedef unsigned long int   uintptr_t;
#else
typedef int                 intptr_t;
typedef unsigned int        uintptr_t;
#endif

#endif /* end of include guard: STDINT_H */
