/*
* Dynamic Arrays
* Written by Hansheng Li
*
* Can store generic value.
* Function Explanation was in the h file.
*
* Last update: 2017-11-29
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "da.h"

struct da
{
	void **array; // the value store in the array.
	int size; //numbers of items in the array;
	int cap; //capacity, number of total.
	void(*display)(FILE *, void *);
};

DA *newDA(void(*d)(FILE *, void *)) //d is the display function
{
	DA *n = (DA*)malloc(sizeof(DA));
	assert(n != 0);
	n->size = 0;
	n->cap = 1;
	n->array = malloc(sizeof(void *) * n->cap);
	assert(n->array != 0);
	n->display = d;
	return n;
}

void insertDA(DA * items, void * value)
{
	if (items->size == items->cap)
	{
		items->array = realloc(items->array, sizeof(void *) *((items->cap) * 2));
		items->cap = items->cap * 2;
	}
	items->array[items->size] = value;
	items->size++;
}

void displayDA(FILE *fp, DA *items)
{
	int i = 0;
	printf("[");
	for (i = 0; i < items->size; ++i)
	{
		items->display(fp, items->array[i]);
		if (i < items->size - 1)
		{
			printf(",");
		}
	}
	printf("]");
}

void visualizeDA(FILE *fp, DA *items)
{
	int i = 0;
	printf("[");
	for (i = 0; i < items->size; ++i)
	{
		items->display(fp, items->array[i]);
		if (i < items->size - 1)
		{
			printf(",");
		}
	}
	printf("]");
	printf("[%d]", items->cap - items->size);

}

void *removeDA(DA *items)
{
	assert(items->size > 0);
	if (items->size == 0)
	{
		printf("array was empty, can't remove.\n");
		return items->array[items->size];
	}

	if ((items->cap > 1) && ((items->size <= 1) || (items->size <= items->cap / 4)))
	{
		items->array = realloc(items->array, sizeof(void *) *((items->cap) / 2));
		items->cap = items->cap / 2;
	}
	items->size--;
	return items->array[items->size];
}

void *getDA(DA *items, int index)
{
	assert((index >= 0) && (index < items->size));
	return items->array[index];
}

void unionDA(DA *recipient, DA *donor)
{
	int i = 0;
	for (i = 0; i < donor->size; i++)
	{
		insertDA(recipient, donor->array[i]);
	}
	donor->array = realloc(donor->array, sizeof(void *));
	donor->size = 0;
	donor->cap = 1;
}

int sizeDA(DA *items)
{
	return items->size;
}

void *setDA(DA *items, int index, void *value)
{
	assert((index >= 0) && (index <= items->size));
	if (index == items->size)
	{
		insertDA(items, value);
		return NULL;
	}

	void *old = items->array[index];
	items->array[index] = value;
	return old;
}

void **extractDA(DA *items)
{
	void **p;
	int i = 0;
	p = malloc(sizeof(void *) * (items->size - 1));
	assert(p != 0);
	for (i = 0; i < items->size; i++)
	{
		p[i] = items->array[i];
	}
	items->array = realloc(items->array, sizeof(void *));
	assert(items->array != 0);
	items->cap = 1;
	items->size = 0;
	return p;
}