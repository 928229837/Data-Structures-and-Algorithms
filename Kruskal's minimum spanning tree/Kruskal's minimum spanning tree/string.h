/*
* String 
* Written by Hansheng Li
*
* Store string in to a pointer and can use as a void pointer.
*
* Last update: 2017-11-29
*/
#ifndef __STRING_INCLUDED__
#define __STRING_INCLUDED__

#include <stdio.h>

typedef struct STRING STRING;

extern STRING *newSTRING(char *);
extern char *getSTRING(STRING *);
extern void freeSTRING(STRING *);
extern char *setSTRING(STRING *, char *);
extern void displaySTRING(FILE *, void *);

#endif
