/*
* bst.c, by Li Hansheng
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include "queue.h"
#include "bst.h"
#include "string.h"

int height(BSTNODE *node);
int minDepth(BSTNODE *root);
bool isLeft(BSTNODE *node, BST *tree);
bool isRight(BSTNODE *node, BST *tree);
BSTNODE *newNode(void* value, BSTNODE *parent);
BSTNODE *search(BSTNODE *root, void* key, int(*comparator)(void *, void *));
BSTNODE *insertNode(BSTNODE *tree, void* value, int(*comparator)(void *, void *));
BSTNODE *getPredecessor(BSTNODE *node);
BSTNODE *getSuccessor(BSTNODE *node);

struct bstnode
{
	void *value;
	struct bstnode *left;
	struct bstnode *right;
	struct bstnode *parent;
};

struct bst
{
	int size;
	struct bstnode *root;
	void(*display)(FILE *, void *);
	int(*comparator)(void *, void *);
	void(*swapper)(BSTNODE *, BSTNODE *);
};

BST *newBST(void(*display)(FILE *, void *), int(*comparator)(void *, void *), void(*swapper)(BSTNODE *, BSTNODE *))
{
	BST *bst = (BST*)malloc(sizeof(BST));
	assert(bst != 0);
	bst->display = display;
	bst->comparator = comparator;
	bst->swapper = swapper;
	bst->root = NULL;
	bst->size = 0;
	return bst;
}

BSTNODE *newNode(void* value, BSTNODE *parent)
{
	BSTNODE *node = (BSTNODE*)malloc(sizeof(BSTNODE));
	assert(node != 0);
	node->value = value;
	node->left = node->right = NULL;
	node->parent = parent;
	return node;
}

BSTNODE *insertBST(BST *tree, void *value)
{
	tree->size++;
	if (tree->root == NULL)
	{
		BSTNODE *node = newNode(value, tree->root);
		tree->root = node;
		tree->root->parent = tree->root;
		return node;
	}
	else if (tree->root->value == NULL)
	{
		tree->root->value = value;
		return tree->root;
	}
	else
		return insertNode(tree->root, value, tree->comparator);
}

BSTNODE *insertNode(BSTNODE *node, void* value, int(*comparator)(void *, void *))
{
	int compare = 0;
	compare = comparator(node->value, value);
	if (compare > 0)//key was smaller, go left.
	{
		if (node->left == NULL)
			return node->left = newNode(value, node);
		return insertNode(node->left,value, comparator);
	}
		
	else if (compare < 0)//compare = 1, key was bigger, go right.
	{
		if (node->right == NULL)
			return node->right = newNode(value, node);
		return insertNode(node->right, value, comparator);
	}
	return node;
}

void displayBST(FILE *fp, BST *tree)
{
	if (tree->root == NULL || tree->root->value == NULL)
	{
		fprintf(fp, "EMPTY\n");
		return;
	}
	int h = height(tree->root);
	int i = 0;
	BSTNODE *temp = tree->root;
	QUEUE *qa = newQUEUE(tree->display);
	QUEUE *qb = newQUEUE(tree->display);
	enqueue(qa, temp);
	for (i = 1; i <= h; i++)
	{
		fprintf(fp, "%d:", i - 1);
		while (sizeQUEUE(qa) > 0)
		{
			fprintf(fp, " ");
			temp = dequeue(qa);
			if (temp->left == NULL && temp->right == NULL)
				fprintf(fp, "=");
			tree->display(fp, temp->value);
			fprintf(fp, "(");
			tree->display(fp, temp->parent->value);
			fprintf(fp, ")-");
			if (isLeft(temp, tree))
				fprintf(fp, "l");
			else if (isRight(temp, tree))
				fprintf(fp, "r");
			if (temp->left != NULL)
				enqueue(qb, temp->left);
			if (temp->right != NULL)
				enqueue(qb, temp->right);
		}
		while (sizeQUEUE(qb) > 0)
			enqueue(qa, dequeue(qb));
		fprintf(fp, "\n");
	}
}

int height(BSTNODE *node)
{
	if (node == NULL || node->value == NULL)// || node->value == NULL
		return 0;
	else
	{
		// compute the height of each subtree 
		int lheight = height(node->left);
		int rheight = height(node->right);
		// use the larger one 
		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}

int minDepth(BSTNODE *root)
{
	if (root == NULL || root->value == NULL)
		return 0;
	if (root->left == NULL || root->right == NULL)
		return 1;
	if (!root->left)
		return minDepth(root->right) + 1;
	if (!root->right)
		return minDepth(root->left) + 1;
	if (minDepth(root->left) < minDepth(root->right))
	{
		return minDepth(root->left) + 1;
	}
	return minDepth(root->right) + 1;
}


BSTNODE *findBST(BST *tree, void *value)
{
	return search(tree->root, value, tree->comparator);
}

BSTNODE *search(BSTNODE *root, void* key, int(*comparator)(void *, void *))
{
	int compare = 0;
	if (root == NULL || root->value == NULL)
		return NULL;
	compare = comparator(root->value, key);
	// Base Cases: root is null or key is present at root
	if (compare == 0)
		return root;
	// Key is greater than root's key
	if (compare < 0)
		return search(root->right, key, comparator);
		// Key is smaller than root's key
	return search(root->left, key, comparator);
}

BSTNODE *deleteBST(BST *tree, void *value)
{
	tree->size--;
	BSTNODE *node = findBST(tree, value);
	node = swapToLeafBST(tree, node);
	pruneLeafBST(tree, node);
	return node;
}

BSTNODE *swapToLeafBST(BST *tree, BSTNODE *node)
{
	BSTNODE *tempNode = node;
	void *temp;
	while (!(node->left == NULL && node->right == NULL))
	{
		if (node->left != NULL)
			tempNode = getPredecessor(node);
		else if (node->right != NULL)
			tempNode = getSuccessor(node);
		if (tree->swapper == NULL)
		{
			temp = node->value;
			node->value = tempNode->value;
			tempNode->value = temp;
		}
		else
			tree->swapper(node, tempNode);
		node = tempNode;
	}
	return node;
}

BSTNODE *getPredecessor(BSTNODE *node)
{
	node = node->left;
	while (node->right != NULL)
		node = node->right;
	return node;
}

BSTNODE *getSuccessor(BSTNODE *node)
{
	node = node->right;
	while (node->left != NULL)
		node = node->left;
	return node;
}


void pruneLeafBST(BST *tree, BSTNODE *leaf)
{
	if (tree->swapper != NULL)
		tree->size--;
	if (isLeft(leaf, tree))
		leaf->parent->left = NULL;
	else if (isRight(leaf, tree))
		leaf->parent->right = NULL;
	else if (leaf->parent->left == NULL && leaf->parent->right == NULL)//It is a root
	{
		leaf->value = NULL;
		return;
	}
	free(leaf);
}

void statisticsBST(FILE *fp, BST *tree)
{
	fprintf(fp, "Nodes: %d\n", tree->size);
	fprintf(fp, "Minimum depth: %d\n", minDepth(tree->root));
	fprintf(fp, "Maximum depth: %d\n", height(tree->root));
}

bool isLeft(BSTNODE *node, BST *tree)
{
	if (node->parent->left != NULL)
		if(!tree->comparator(node->value, node->parent->left->value))
			return true;
	return false;
}

bool isRight(BSTNODE *node, BST *tree)
{
	if (node->parent->right != NULL)
		if (!tree->comparator(node->value, node->parent->right->value))
			return true;
	return false;
}

int sizeBST(BST *t)
{
	return t->size;
}
void setBSTroot(BST *t, BSTNODE *replacement)
{
	t->root = replacement;
	t->root->parent = t->root;
}

BSTNODE *getBSTroot(BST *t)
{
	return t->root;
}

void *getBSTNODE(BSTNODE *n)
{
	return n->value;
}

void setBSTNODE(BSTNODE *n, void *value)
{
	n->value = value;
}

BSTNODE *getBSTNODEleft(BSTNODE *n)
{
	return n->left;
}

void setBSTNODEleft(BSTNODE *n, BSTNODE *replacement)
{
	n->left = replacement;
}

BSTNODE *getBSTNODEright(BSTNODE *n)
{
	return n->right;
}

void setBSTNODEright(BSTNODE *n, BSTNODE *replacement)
{
	n->right = replacement;
}

BSTNODE *getBSTNODEparent(BSTNODE *n)
{
	return n->parent;
}

void setBSTNODEparent(BSTNODE *n, BSTNODE *replacement)
{
	n->parent = replacement;
}
