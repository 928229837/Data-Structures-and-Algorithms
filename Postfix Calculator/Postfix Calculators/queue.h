/*
* Queue 
* Written by Hansheng Li
*
* Built upon the circular dynamic array class.
*
* Last update: 2017-11-29
*/
#ifndef __QUEUE_INCLUDED__
#define __QUEUE_INCLUDED__

#include <stdio.h>

typedef struct queue QUEUE;

extern QUEUE *newQUEUE(void(*d)(FILE *, void *));

extern int sizeQUEUE(QUEUE *items);

extern void *dequeue(QUEUE *items);
extern void *peekQUEUE(QUEUE *items);
extern void enqueue(QUEUE *items, void *value);
extern void displayQUEUE(FILE *, QUEUE *items);
//Print all circular dynamic array's value from head to tail in that Queue.
extern void visualizeQUEUE(FILE *, QUEUE *items);
//Just call DisplayCDA.

#endif