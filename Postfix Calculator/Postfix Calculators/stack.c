/*
* Stack
* Written by Hansheng Li
*
* Built upon the dynamic array class.
*
* Last update: 2017-11-29
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "da.h"
#include "stack.h"


struct stack
{
	DA *stackArray; //point stack struct to use DA
	void(*display)(FILE *, void *);
};

STACK *newSTACK(void(*d)(FILE *, void *))
{
	STACK *stack = (STACK*)malloc(sizeof(STACK));
	stack->stackArray = newDA(d);
	assert(stack != 0);
	stack->display = d;
	return stack;
}

void push(STACK *items, void *value)
{
	insertDA(items->stackArray, value);
}

void *pop(STACK *items)
{
	assert(sizeDA(items->stackArray) > 0);
	if (sizeDA(items->stackArray) == 0)
	{
		return getDA(items->stackArray, sizeDA(items->stackArray) );
	}
	void *pop;
	pop = getDA(items->stackArray, sizeDA(items->stackArray) - 1);
	removeDA(items->stackArray);
	return pop;
}

void *peekSTACK(STACK *items)
{
	assert(sizeDA(items->stackArray) > 0);
	return getDA(items->stackArray, sizeDA(items->stackArray) - 1);
}

int sizeSTACK(STACK *items)
{
	return sizeDA(items->stackArray);
}

void displaySTACK(FILE *fp, STACK * items)
{
	int i = 0;
	printf("|");
	for (i = sizeDA(items->stackArray) - 1; i >= 0; i--)
	{
		items->display(fp, getDA(items->stackArray, i));
		if (i != 0)
		{
			printf(",");
		}
	}
	printf("|");
}

void visualizeSTACK(FILE *fp, STACK *items)
{
	displayDA(fp, items->stackArray);
}
