/*
* Red-black binary search tree
* Written by Hansheng Li
*
* Last update: 2017-11-29
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "rbt.h"
#include "bst.h"

typedef struct RBTVALUE RBTVALUE;

bool isRoot(BSTNODE* node);
bool isLinear(BSTNODE* node);
bool isLeftRBT(BSTNODE* node);
bool isRightRBT(BSTNODE* node);

BSTNODE *getUncle(BSTNODE* node);
BSTNODE *getNiece(BSTNODE* node);
BSTNODE *getNephew(BSTNODE* node);
BSTNODE *getSibling(BSTNODE* node);
BSTNODE *getGrandpa(BSTNODE* node);
RBTVALUE *newRBTVALUE(void *value, RBT *tree);
RBTVALUE *searchRBTVALUE(RBT *rbt, void *value);

int RBTcomparator(void *va, void *vb);

void swapper(BSTNODE *a, BSTNODE *b);
void leftRotate(RBT *tree, BSTNODE *x);
void rightRotate(RBT *tree, BSTNODE *y);
void RBTvalueDisplay(FILE* fp, void* va);
void deletionFixUp(RBT *tree, BSTNODE *x);
void insertionFixUp(RBT *tree, BSTNODE *x);
void rotate(RBT *tree, BSTNODE *x, BSTNODE *parent);

struct RBTVALUE
{
	void *value;
	int count;
	char colour; 
	void(*display)(FILE *, void *);
	int(*comparator)(void *, void *);
};

struct rbt
{
	struct bst *rt;
	int words;
	void(*display)(FILE *, void *);
	int(*comparator)(void *, void *);
	void(*swapper)(BSTNODE *, BSTNODE *);
};

RBTVALUE *newRBTVALUE(void *value, RBT *tree)
{
	RBTVALUE *node = (RBTVALUE*)malloc(sizeof(RBTVALUE));
	assert(node != 0);
	node->value = value;
	node->colour = 'R';
	node->count = 1;
	node->display = tree->display;
	node->comparator = tree->comparator;
	return node;
}

RBT *newRBT(void(*display)(FILE *, void *), int(*comparator)(void *, void *))
{
	RBT *rbt = (RBT*)malloc(sizeof(RBT));
	assert(rbt != 0);
	rbt->display = display;
	rbt->comparator = comparator;
	rbt->swapper = swapper;
	rbt->words = 0;
	rbt->rt = newBST(RBTvalueDisplay , RBTcomparator, swapper);
	return rbt;
}

void swapper(BSTNODE *a, BSTNODE *b)
{
	RBTVALUE *ra = getBSTNODE(a);
	RBTVALUE *rb = getBSTNODE(b);
	/* swap the keys stored in the RBT value objects */
	void *vtemp = ra->value;
	ra->value = rb->value;
	rb->value = vtemp;
	/* swap the counts stored in the RBT value objects */
	int ctemp = ra->count;
	ra->count = rb->count;
	rb->count = ctemp;
	/* note: colors are NOT swapped */
}

int RBTcomparator(void *va, void *vb)
{  // B smaller ->  1;
   // B bigger  -> -1; 
   // A B equal ->  0; 
	RBTVALUE *ra = va;
	RBTVALUE *rb = vb;
	return rb->comparator(ra->value, rb->value);
}

void RBTvalueDisplay(FILE* fp, void* va)
{
	RBTVALUE *ra = va;
	ra->display(fp, ra->value);
	if (ra->count > 1)
		fprintf(fp, "-%d", ra->count);
	fprintf(fp, "-%c", ra->colour);
}

void insertRBT(RBT *rbt, void *value)
{
	RBTVALUE *rtv = searchRBTVALUE(rbt, value);
	if (rtv == NULL)
	{
		rtv = newRBTVALUE(value, rbt);
		BSTNODE *node = insertBST(rbt->rt, rtv);
		insertionFixUp(rbt, node);
	}
	else
		rtv->count++;
	rbt->words++;
	//displayRBT(stdout, rbt);
}

void *get_RBT_minimum(RBT *rbt)
{
	BSTNODE *node = getBSTroot(rbt->rt);
	while (getBSTNODEleft(node) != NULL)
		node = getBSTNODEleft(node);
	RBTVALUE *rv = getBSTNODE(node);
	return rv->value;
}

void insertionFixUp(RBT *tree, BSTNODE *x)    // x is the newly inserted node
{
	BSTNODE *parent = getBSTNODEparent(x);
	RBTVALUE *parentValue = getBSTNODE(parent);

	BSTNODE *root = getBSTroot(tree->rt);
	RBTVALUE *rootValue = getBSTNODE(root);

	//exit when x is root or parent is black
	while (!isRoot(x) && parentValue->colour == 'R')
	{
		BSTNODE *grandpa = getGrandpa(x);
		RBTVALUE *grandpaValue = getBSTNODE(grandpa);

		BSTNODE *uncle = getUncle(x);
		RBTVALUE *uncleValue = parentValue;
		char uncleColour = 'B';
		if (uncle != NULL)
		{
			uncleValue = getBSTNODE(uncle);
			uncleColour = uncleValue->colour;
		}

		parentValue = getBSTNODE(parent);

		if (uncleColour == 'R')
		{
			parentValue->colour = 'B';
			uncleValue->colour = 'B';
			grandpaValue->colour = 'R';
			x = grandpa;
			parent = getBSTNODEparent(x);
			parentValue = getBSTNODE(parent);
		}
		else// uncle must be black
		{
			if (!isLinear(x))
			{
				rotate(tree, x, parent);//rotate x to parent
				BSTNODE* temp = x;
				x = parent;
				parent = temp;
				parentValue = getBSTNODE(parent);
			}
			parentValue->colour = 'B';
			grandpaValue->colour = 'R';
			rotate(tree, parent, grandpa);//rotate parent to grandparent
			root = getBSTroot(tree->rt);
			rootValue = getBSTNODE(root);
			break;
		}
	}
	rootValue->colour = 'B';
}

void deleteRBT(RBT *rbt, void *value)
{
	BSTNODE *node = findBST(rbt->rt, newRBTVALUE(value, rbt));
	if (node == NULL)
	{
		printf("Value ");
		rbt->display(stdout, value);
		printf(" not found.\n");
		return;
	}
	RBTVALUE *rbtv = getBSTNODE(node);
	if (rbtv->count > 1)
		rbtv->count--;
	else
	{
		node = swapToLeafBST(rbt->rt, node);
		rbtv = getBSTNODE(node);

		if (rbtv->colour == 'B')
			deletionFixUp(rbt, node);
		pruneLeafBST(rbt->rt, node);
	}
	rbt->words--;
}

void deletionFixUp(RBT *tree, BSTNODE *x)
{
	char siblingColour = 'B';
	char nephewColour = 'B';
	char nieceColour = 'B';

	RBTVALUE *xValue = getBSTNODE(x);
	//exit when x is root or x is black
	while (!isRoot(x) && xValue->colour == 'B')
	{
		BSTNODE *parent = getBSTNODEparent(x);
		RBTVALUE *parentValue = getBSTNODE(parent);

		BSTNODE *sibling = getSibling(x);
		if (sibling != NULL)
		{
			RBTVALUE *siblingValue = getBSTNODE(sibling);
			siblingColour = siblingValue->colour;

			RBTVALUE *nephewValue = siblingValue;
			BSTNODE *nephew = getNephew(x);
			if (nephew != NULL)
			{
				nephewValue = getBSTNODE(nephew);
				nephewColour = nephewValue->colour;
			}

			RBTVALUE *nieceValue = siblingValue;
			BSTNODE *niece = getNiece(x);
			if (niece != NULL)
			{
				nieceValue = getBSTNODE(niece);
				nieceColour = nieceValue->colour;
			}

			if (siblingColour == 'R')
			{
				parentValue->colour = 'R';
				siblingColour = siblingValue->colour = 'B';
				rotate(tree, sibling, parent);//rotate sibling to parent
				//should have black sibling now
			}
			else if (nephewColour == 'R')
			{
				siblingValue->colour = parentValue->colour;
				parentValue->colour = 'B';
				nephewColour = nephewValue->colour = 'B';
				rotate(tree, sibling, parent);//rotate sibling to parent
				// subtree and tree is BH balanced
				break;
			}
			else if (nieceColour == 'R')
			{
				// nephew must be black
				nieceValue->colour = 'B';
				siblingValue->colour = 'R';
				rotate(tree, niece, sibling);//rotate niece to sibling
				// should have red nephew now
			}
			else// sibling, niece, and nephew must be black
			{
				siblingValue->colour = 'R';
				x = parent;
				xValue = getBSTNODE(x);
				// this subtree is BH balanced, but tree is not
			}
		}
	}
	xValue->colour = 'B';
}

int findRBT(RBT *rbt, void *value)
{
	RBTVALUE *rtv = searchRBTVALUE(rbt, value);
	if (rtv == NULL)
		return 0;
	return rtv->count;
}

RBTVALUE *searchRBTVALUE(RBT *rt, void *value)
{
	RBTVALUE *findNode = newRBTVALUE(value, rt);
	BSTNODE *bstnode = findBST(rt->rt, findNode);
	if (bstnode == NULL)
		return NULL;
	RBTVALUE *rtnode = getBSTNODE(bstnode);
	return rtnode;
}

void *findRBTvalue(RBT *rbt, void *value)
{
	RBTVALUE *findNode = newRBTVALUE(value, rbt);
	BSTNODE *bstnode = findBST(rbt->rt, findNode);
	if (bstnode == NULL)
		return NULL;
	RBTVALUE *rtnode = getBSTNODE(bstnode);
	return rtnode->value;
}

void displayRBT(FILE *fp, RBT *tree)
{
	displayBST(fp, tree->rt);
}

int sizeRBT(RBT *rt)
{
	return sizeBST(rt->rt);
}

int wordsRBT(RBT *rt)
{
	return rt->words;
}

void statisticsRBT(FILE *fp, RBT *tree)
{
	fprintf(fp, "Words/Phrases: %d\n", wordsRBT(tree));
	statisticsBST(fp, tree->rt);
}

bool isRoot(BSTNODE* node)
{
	if (!RBTcomparator(getBSTNODE(node), getBSTNODE(getBSTNODEparent(node))))
		return true;
	return false;
}

BSTNODE *getUncle(BSTNODE* node)
{
	if(isLeftRBT(getBSTNODEparent(node)))
		return getBSTNODEright(getGrandpa(node));
	return getBSTNODEleft(getGrandpa(node));
}

BSTNODE *getGrandpa(BSTNODE* node)
{
	return getBSTNODEparent(getBSTNODEparent(node));
}

BSTNODE *getSibling(BSTNODE* node)
{
	if (isLeftRBT(node))
		return getBSTNODEright(getBSTNODEparent(node));
	return getBSTNODEleft(getBSTNODEparent(node));
}

BSTNODE *getNephew(BSTNODE* node)
{
	if (isLeftRBT(node))
		return getBSTNODEright(getSibling(node));
	return getBSTNODEleft(getSibling(node));
}

BSTNODE *getNiece(BSTNODE* node)
{
	if (isLeftRBT(node))
		return getBSTNODEleft(getSibling(node));
	return getBSTNODEright(getSibling(node));
}

bool isLeftRBT(BSTNODE* node)
{
	if (getBSTNODEleft(getBSTNODEparent(node)) != NULL && !RBTcomparator(getBSTNODE(getBSTNODEleft(getBSTNODEparent(node))), getBSTNODE(node)))
		return true;
	return false;
}

bool isRightRBT(BSTNODE* node)
{
	if (getBSTNODEright(getBSTNODEparent(node)) != NULL && !RBTcomparator(getBSTNODE(getBSTNODEright(getBSTNODEparent(node))), getBSTNODE(node)))
		return true;
	return false;
}

bool isLinear(BSTNODE* node)
{
	if ((isLeftRBT(node) && isLeftRBT(getBSTNODEparent(node))) || (isRightRBT(node) && isRightRBT(getBSTNODEparent(node))))
		return true;
	return false;
}

void rotate(RBT *tree, BSTNODE *x, BSTNODE *parent)
{
	if (isRightRBT(x))
		leftRotate(tree, parent);
	else//is Left
		rightRotate(tree, parent);
}

void leftRotate(RBT *tree, BSTNODE *x)
{
	BSTNODE *y = getBSTNODEright(x);
	setBSTNODEright(x, getBSTNODEleft(y));

	if (getBSTNODEleft(y) != NULL)
		setBSTNODEparent(getBSTNODEleft(y), x);


	if (isRoot(x))
		setBSTroot(tree->rt, y);
	else
	{
		setBSTNODEparent(y, getBSTNODEparent(x));

		if (isLeftRBT(x))
			setBSTNODEleft(getBSTNODEparent(x), y);
		else
			setBSTNODEright(getBSTNODEparent(x), y);
	}

	setBSTNODEleft(y, x);
	setBSTNODEparent(x, y);
}

void rightRotate(RBT *tree, BSTNODE *y)
{
	BSTNODE *x = getBSTNODEleft(y);
	setBSTNODEleft(y, getBSTNODEright(x));

	if (getBSTNODEright(x) != NULL)
		setBSTNODEparent(getBSTNODEright(x), y);

	if (isRoot(y))
		setBSTroot(tree->rt, x);
	else
	{
		setBSTNODEparent(x, getBSTNODEparent(y));

		if (isLeftRBT(y))
			setBSTNODEleft(getBSTNODEparent(y), x);
		else
			setBSTNODEright(getBSTNODEparent(y), x);
	}

	setBSTNODEright(x, y);
	setBSTNODEparent(y, x);
}