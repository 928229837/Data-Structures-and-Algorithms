/*** green binary search tree class ***/

#ifndef __GT_INCLUDED__
#define __GT_INCLUDED__

#include <stdio.h>

typedef struct gt GT;

extern GT *newGT(void(*display)(FILE *, void *), int(*comparator)(void *, void *));
extern void insertGT(GT *, void *);
extern int findGT(GT *, void *);
extern void deleteGT(GT *, void *);
extern int sizeGT(GT *);//Show numbers of nodes
extern int wordsGT(GT *);//Show numbers of words
extern void statisticsGT(FILE *, GT *);
extern void displayGT(FILE *, GT *);

#endif