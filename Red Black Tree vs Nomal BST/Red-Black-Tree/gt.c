/*
* gt.c, by Li Hansheng
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "gt.h"
#include "bst.h"

typedef struct GTVALUE GTVALUE;

int GTcomparator(void* va, void* vb);
void GTvalueDisplay(FILE* fp, void* va);
GTVALUE *newGTVALUE(void* val, GT* tree);
GTVALUE *searchGTVALUE(GT *gt, void *value);

struct GTVALUE
{
	void *value;
	int count;
	void(*display)(FILE *, void *);
	int(*comparator)(void *, void *);
};

struct gt
{
	struct bst *gt;
	int words;
	void(*display)(FILE *, void *);
	int(*comparator)(void *, void *);
};

GT *newGT(void(*display)(FILE *, void *), int(*comparator)(void *, void *))
{
	GT *tree = (GT*)malloc(sizeof(GT));
	assert(tree != 0);
	tree->words = 0;
	tree->comparator = comparator;
	tree->display = display;
	tree->gt = newBST(GTvalueDisplay, GTcomparator, NULL);
	return tree;
}

GTVALUE *newGTVALUE(void* val, GT* tree)
{
	GTVALUE *node = (GTVALUE*)malloc(sizeof(GTVALUE));
	assert(node != 0);
	node->comparator = tree->comparator;
	node->display = tree->display;
	node->value = val;
	node->count = 1;
	return node;
}

void insertGT(GT *tree, void *value)
{
	GTVALUE *gv = searchGTVALUE(tree, value);
	if (gv == NULL)
	{
		gv = newGTVALUE(value, tree);
		insertBST(tree->gt, gv);
	}
	else 
		gv->count++;
	tree->words++;
}

void displayGT(FILE *fp, GT *tree)
{
	displayBST(fp, tree->gt);
}

int findGT(GT *gt, void *value)
{
	GTVALUE *gtv = searchGTVALUE(gt, value);
	if (gtv == NULL)
		return 0;
	return gtv->count;
}

GTVALUE *searchGTVALUE(GT *gt, void *value)
{
	GTVALUE *findNode = newGTVALUE(value, gt);
	BSTNODE *bstnode = findBST(gt->gt, findNode);
	if (bstnode == NULL)
		return NULL;
	GTVALUE *gtnode = getBSTNODE(bstnode);
	return gtnode;
}

void deleteGT(GT *gt, void *value)
{
	BSTNODE *node = findBST(gt->gt, newGTVALUE(value, gt));
	if (node == NULL)
	{
		printf("Value ");
		gt->display(stdout, value);
		printf(" not found.\n");
		return;
	}

	GTVALUE *gtv = getBSTNODE(node);
	if (gtv->count > 1)
		gtv->count--;
	else
		deleteBST(gt->gt, gtv);
	gt->words--;
}

int sizeGT(GT *tree)
{
	return sizeBST(tree->gt);
}

int wordsGT(GT *gt)
{
	return gt->words;
}

void statisticsGT(FILE *fp, GT *tree)
{
	printf("Words/Phrases: %d\n", wordsGT(tree));
	statisticsBST(fp, tree->gt);
}

int GTcomparator(void* va, void* vb)
{   // B smaller ->  1;
	// B bigger  -> -1; 
	// A B equal ->  0; 
	GTVALUE *ga = va; 
	GTVALUE *gb = vb;
	return ga->comparator(ga->value, gb->value);
}

void GTvalueDisplay(FILE* fp, void* va)
{
	GTVALUE *ga = va;
	ga->display(fp, ga->value);
	if (ga->count > 1)
		printf("-%d",ga->count);
}