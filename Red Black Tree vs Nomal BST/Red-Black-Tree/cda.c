/*
* Circular Dynamic Arrays
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
#include "cda.h"

struct cda
{
	void **array; // the value store in the array.
	int size; //numbers of items in the array;
	int cap; //capacity, number of total.
	int head;
	int tail;
	void(*display)(FILE *, void *);
};

CDA *newCDA(void(*d)(FILE *, void *))
{
	CDA *n = (CDA*)malloc(sizeof(CDA));
	assert(n != 0);
	n->size = 0;
	n->cap = 1;
	n->array = malloc(sizeof(void *) * n->cap);
	assert(n->array != 0);
	n->head = 0;
	n->tail = 0;
	n->display = d;
	return n;
}

void insertCDAfront(CDA *items, void *value)
{
	if (items->size == items->cap)//double array when array was full.
	{
		int i = 0;
		int next = items->head;///next copy index.
		CDA *temp = (CDA*)malloc(sizeof(CDA));
		assert(temp != 0);
		items->cap = items->cap * 2;
		temp->cap = items->cap;
		temp->size = items->size;
		temp->array = malloc(sizeof(void *) * temp->cap);
		assert(temp->array != 0);
		for (i = 0; i < temp->size; i++)
		{
			temp->array[i] = items->array[next];
			next = (next + 1) % (items->cap / 2);
		}
		items->array = temp->array;
		items->head = 0;
		items->tail = (items->cap / 2) - 1;
	}
	if ((items->head - 1) < 0)
	{
		if ((items->cap == 1) || (items->size == 0))
		{
			items->head = 0;
		}
		else
		{
			items->head = items->cap - 1;
		}
	}
	else
	{
		items->head--;
	}
	items->array[items->head] = value;
	items->size++;
}

void insertCDAback(CDA *items, void *value)
{
	if (items->size == items->cap)//double array.
	{
		int i = 0;
		int next = items->head;///next copy index.
		CDA *temp = (CDA*)malloc(sizeof(CDA));
		assert(temp != 0);
		items->cap = items->cap * 2;
		temp->cap = items->cap;
		temp->size = items->size;
		temp->array = malloc(sizeof(void *) * temp->cap);
		assert(temp->array != 0);
		for (i = 0; i < temp->size; i++)
		{
			temp->array[i] = items->array[next];
			next = (next + 1) % (items->cap / 2);
		}
		items->array = temp->array;
		items->head = 0;
		items->tail = (items->cap / 2) - 1;
	}
	items->tail = (items->tail + 1) % items->cap;
	items->array[items->tail] = value;
	items->size++;
}

void visualizeCDA(FILE *fp, CDA *items)
{
	int i = 0;
	int next = items->head;//next index need to be print
	printf("(");
	for (i = 0; i<items->size; i++)
	{
		items->display(fp, items->array[next]);
		next = (next + 1) % (items->cap);
		if (i < items->size - 1)
		{
			printf(",");
		}
	}
	printf(")");
	printf("(%d)", items->cap - items->size);
}

void *removeCDAfront(CDA *items)
{
	assert(items->size > 0);
	if (items->size == 0)
	{
		printf("array was empty, can't remove.\n");
		return items->array[items->size - 1];
	}
	else if ((items->cap > 1) && ((items->size <= 1) || (items->size - 1 <= items->cap / 4)))
		//shrink array to half.
	{
		int i = 0;
		int next = items->head;//next copy index.
		CDA *temp = (CDA*)malloc(sizeof(CDA));
		assert(temp != 0);
		temp->cap = items->cap / 2;
		temp->size = items->size;
		temp->array = malloc(sizeof(void *) * temp->cap);
		assert(temp->array != 0);
		for (i = 0; i < temp->size; i++)
		{
			temp->array[i] = items->array[next];
			next = (next + 1) % (items->cap);
		}
		items->cap = items->cap / 2;
		items->array = temp->array;
		items->size--;
		if (items->size >= 1)
		{
			items->tail = items->size;
			items->head = 1;
		}
		else
		{
			items->tail = 0;
			items->head = 0;
		}
	}
	else
	{
		items->size--;
		if (items->size <= 1)
		{
			items->array[items->head] = items->array[items->tail];
			items->head = 0;
			items->tail = 0;
		}
		else
		{
			items->head = (items->head + 1) % items->cap;
		}
	}
	assert(items->size >= 0);
	return items->array[items->size];
}

void *removeCDAback(CDA *items)
{
	assert(items->size > 0);
	if (items->size == 0)
	{
		printf("array was empty, can't remove.\n");
		return items->array[items->size - 1];
	}
	else if ((items->cap > 1) && ((items->size <= 1) || (items->size <= items->cap / 4)))
		//shrink array to half.
	{
		int i = 0;
		int next = items->head;///next copy index.
		CDA *temp = (CDA*)malloc(sizeof(CDA));
		assert(temp != 0);
		temp->cap = items->cap / 2;
		temp->size = items->size;
		temp->array = malloc(sizeof(void *) * temp->cap);
		assert(temp->array != 0);
		for (i = 0; i < temp->size; i++)
		{
			temp->array[i] = items->array[next];
			next = (next + 1) % (items->cap);
		}
		items->cap = items->cap / 2;
		items->array = temp->array;
		items->head = 0;
		items->size--;
		if (items->size > 0)
		{
			items->tail = items->size - 1;
		}
		else
		{
			items->tail = 0;
		}
	}
	else
	{
		items->size--;
		if ((items->tail - 1) < 0)
		{
			if (items->cap == 1)
			{
				items->tail = 0;
			}
			else
			{
				items->tail = items->cap - 1;
			}
		}
		else
		{
			items->tail--;
		}
	}
	assert(items->size >= 0);
	return items->array[items->size];
}

void unionCDA(CDA *recipient, CDA *donor)
{
	int i = 0;
	int next = donor->head;
	for (i = 0; i < donor->size; i++)
	{
		insertCDAback(recipient, donor->array[next]);
		next = (next + 1) % donor->cap;
	}
	donor->array = realloc(donor->array, sizeof(void *));
	donor->size = 0;
	donor->cap = 1;
	donor->head = 0;
	donor->tail = 0;
}

void *getCDA(CDA *items, int index)
{
	assert((index >= 0) && (index < items->size));
	if ((index >= items->size) || (index < 0))
	{
		printf("Index was too big or too small.\n");
		return NULL;
	}
	return items->array[((items->head + index) % items->cap)];
}

void *setCDA(CDA *items, int index, void *value)
{
	assert((index >= -1) && (index <= items->size));
	if (index == items->size)
	{
		insertCDAback(items, value);
		return NULL;
	}
	else if (index == -1)
	{
		insertCDAfront(items, value);
		return NULL;
	}

	void *old = items->array[((items->head + index) % items->cap)];
	items->array[((items->head + index) % items->cap)] = value;
	return old;
}

void **extractCDA(CDA *items)
{
	void **p;
	int next = items->head;///next copy index.
	p = malloc(sizeof(void *) * items->size);
	assert(p != 0);
	for (int i = 0; i < items->size; i++)
	{
		for (i = 0; i < items->size; i++)
		{
			p[i] = items->array[next];
			next = (next + 1) % items->cap;
		}
	}
	items->array = realloc(items->array, sizeof(void *));
	assert(items->array != 0);
	items->cap = 1;
	items->size = 0;
	items->head = 0;
	items->tail = 0;
	return p;
}

int sizeCDA(CDA *items)
{
	return items->size;
}

void displayCDA(FILE *fp, CDA *items)
{
	int i = 0;
	int next = items->head;//next index need to be print
	printf("(");
	for (i = 0; i<items->size; i++)
	{
		items->display(fp, items->array[next]);
		next = (next + 1) % (items->cap);
		if (i < items->size - 1)
		{
			printf(",");
		}
	}
	printf(")");
}