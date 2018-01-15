/*
* Circular Dynamic Arrays
* Written by Hansheng Li
*
* Can store generic value.
*
* Last update: 2017-11-29
*/
#ifndef __CDA_INCLUDED__
#define __CDA_INCLUDED__

#include <stdio.h>

typedef struct cda CDA;

extern CDA *newCDA(void(*d)(FILE *, void *));

extern int sizeCDA(CDA *items);

extern void **extractCDA(CDA *items);
extern void *removeCDAback(CDA *items);
extern void *removeCDAfront(CDA *items);
extern void *getCDA(CDA *items, int index);
extern void displayCDA(FILE *, CDA *items);
extern void visualizeCDA(FILE *, CDA *items);
extern void unionCDA(CDA *recipient, CDA *donor);
extern void insertCDAback(CDA *items, void *value);
extern void insertCDAfront(CDA *items, void *value);
extern void *setCDA(CDA *items, int index, void *value);

#endif