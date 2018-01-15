/*
* Dynamic Arrays 
* Written by Hansheng Li
*
* Can store generic value.
*
* Last update: 2017-11-29
*/
#ifndef __DA_INCLUDED__
#define __DA_INCLUDED__

#include <stdio.h>

typedef struct da DA;

extern DA *newDA(void(*display)(FILE *, void *));
//Get a display function.
extern int sizeDA(DA *items);
extern void *removeDA(DA *items);
extern void **extractDA(DA *items);
extern void *getDA(DA *items, int index);
extern void displayDA(FILE *fp, DA *items);
extern void visualizeDA(FILE *fp, DA *items);
//Display and follow by size of the unfilled region
//e.g. [5,6,2,9,1][3]
extern void insertDA(DA *items, void *value);
extern void unionDA(DA *recipient, DA *donor);
//Insert donor's value to recipient and become empty.
extern void *setDA(DA *items, int index, void *value);

#endif