/*
* Disjoint Set
* Written by Hansheng Li
*
* Have Pass Comparison & Union by Rank.
* Function Explanation was in the h file.
* 
* Last update: 2017-11-29
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "da.h"
#include "set.h"

typedef struct disNode DisNode;
DisNode *newDisNode(void* value);
DisNode *path_compression(DisNode *node);

struct set
{
	DA *setArr;//To store value in a dynamic array.
	void(*display)(FILE *, void *);//Display function.
};

struct disNode
{
	int rank;
	void *value;
	DisNode *parent;
};

DisNode *newDisNode(void* value)
{
	DisNode *disNode = (DisNode*)malloc(sizeof(DisNode));
	assert(disNode != 0);
	disNode->value = value;
	disNode->parent = disNode;
	disNode->rank = 0;
	return disNode;
}

SET *newSET(void(*display)(FILE *, void *))
{
	SET *set = (SET*)malloc(sizeof(SET));
	assert(set != 0);
	set->display = display;
	set->setArr = newDA(display);
	return set;
}

int makeSET(SET *set, void *value)
{
	DA *tempArray = set->setArr;
	int arraySize = sizeDA(tempArray);
	insertDA(tempArray, newDisNode(value));
	return arraySize;
}

void displaySET(FILE *fp, SET *set)
{
	int i = 0;
	DisNode *disNode;
	DA *vertexArray = set->setArr;
	int size = sizeDA(set->setArr);
	for (i = 0; i < size; i++)
	{
		disNode = getDA(vertexArray, i);
		printf("%d: ", i);
		set->display(fp, disNode->value);
		while (disNode != disNode->parent)
		{
			printf(" ");
			disNode = disNode->parent;
			set->display(fp, disNode->value);
		}
		printf("\n");
	}
}

int findSET(SET *set, int index)
{
	int i = 0;
	DA *vertexArray = set->setArr;
	DisNode *node = getDA(vertexArray, index);
	path_compression(node);
	DisNode *disNode = node->parent;
	DisNode *temp = getDA(vertexArray, i++);
	while (disNode != temp)
		temp = getDA(vertexArray, i++);
	return i - 1;
}

DisNode *path_compression(DisNode *node)
{
	if (node->parent != node)
		node->parent = path_compression(node->parent);
	return node->parent;
}

int unionSET(SET *set, int index1, int index2)
{
	DA *vertexArray = set->setArr;
	DisNode *a = getDA(vertexArray, findSET(set, index1));
	DisNode *b = getDA(vertexArray, findSET(set, index2));
	if (a == b)
		return 0;
	if (a->rank == b->rank)
	{
		if (index1 < index2)
		{
			b->parent = a;
			a->rank++;
		}
		else
		{
			a->parent = b;
			b->rank++;
		}
	}
	else if (a->rank > b->rank)
		b->parent = a;
	else
		a->parent = b;
	return 1;
}

int countSET(SET *set)
{
	DA *vertexArray = set->setArr;
	return sizeDA(vertexArray);
}