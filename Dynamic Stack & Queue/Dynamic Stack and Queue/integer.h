/*
* Integer 
* Written by Hansheng Li
*
* Store integer in to a pointer and can use as a void pointer.
*
* Last update: 2017-11-29
*/
#ifndef __INTEGER_INCLUDED__
#define __INTEGER_INCLUDED__

#include <stdio.h>

typedef struct INTEGER INTEGER;

extern INTEGER *newINTEGER(int);
extern void freeINTEGER(INTEGER *);
extern int setINTEGER(INTEGER *, int);
extern void displayINTEGER(FILE *,void *);

#endif
