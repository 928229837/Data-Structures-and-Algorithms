/*
* Red-black binary search tree
* Written by Hansheng Li
*
* Last update: 2017-11-29
*/

#ifndef __RBT_INCLUDED__
#define __RBT_INCLUDED__

#include <stdio.h>

typedef struct rbt RBT;

extern RBT *newRBT(void(*display)(FILE *, void *), int(*comparator)(void *, void *));

extern int sizeRBT(RBT *);
extern int wordsRBT(RBT *);
extern int findRBT(RBT *, void *);

extern void *get_RBT_minimum(RBT *);//Get the minimum Node in the RBT.
extern void insertRBT(RBT *, void *);
extern void deleteRBT(RBT *, void *);
extern void displayRBT(FILE *, RBT *);
extern void *findRBTvalue(RBT *, void *);
extern void statisticsRBT(FILE *, RBT *);
//Display Minimum adn Maximum hights and numbers of node.

#endif