/*
* Queue 
* Written by Hansheng Li
*
* Built upon the circular dynamic array class.
*
* Last update: 2017-11-29
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cda.h"
#include "queue.h"

struct queue
{
	CDA *queueArray;
	void(*display)(FILE *, void *);
};

QUEUE *newQUEUE(void(*d)(FILE *, void *))
{
	QUEUE *queue = (QUEUE*)malloc(sizeof(QUEUE));
	queue->queueArray = newCDA(d);
	queue->display = d;
	assert(queue != 0);
	return queue;
}

void enqueue(QUEUE *items, void *value)
{
	insertCDAback(items->queueArray, value);
}

void *dequeue(QUEUE *items)
{
	if (sizeCDA(items->queueArray) == 0)
	{
		return getCDA(items->queueArray, 0);
	}
	void *deq;
	deq = getCDA(items->queueArray, 0);
	removeCDAfront(items->queueArray);
	return deq;
}

void *peekQUEUE(QUEUE *items)
{
	return getCDA(items->queueArray, 0);
}

int sizeQUEUE(QUEUE *items)
{
	return sizeCDA(items->queueArray);
}

void displayQUEUE(FILE *fp, QUEUE *items)
{
	int i = 0;
	printf("<");
	for (i = 0; i < sizeCDA(items->queueArray); i++)
	{
		void *temp = getCDA(items->queueArray, i);
		if (temp == NULL)
			printf("NULL");
		else
			items->display(fp, temp);
		if (i != sizeCDA(items->queueArray) - 1)
		{
			printf(",");
		}
	}
	printf(">");
}

void visualizeQUEUE(FILE *fp, QUEUE *items)
{
	displayCDA(fp, items->queueArray);
}

