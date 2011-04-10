#ifndef STRING_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define STRING_H

#include <stddef.h>

int strlen(const char *str);

char *strcpy(char *s, char *ct);
char *strncpy(char *s, char *ct, int n);
size_t strlcpy(char *dst, const char *src, size_t siz);

char *strcat(char *s, char *ct);
char *strncat(char *s, char *ct, int n);
size_t strlcat(char *dst, const char *src, size_t siz);

int strcmp(char *cs, char *ct);
int strncmp(char *cs, char *ct, int n);

char *strchr(char *cs, int c);
char *strrchr(char *cs, int c);

#endif /* end of include guard: STRING_H */
