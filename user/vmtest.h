#ifndef VMTEST_H
#define VMTEST_H


typedef unsigned long uint64;

int printf(const char*, ...);
int exit(int);

long strtol(const char*, char**, int);
uint64 vtop(uint64);
uint64 hex2uint64(const char *str);
#endif
