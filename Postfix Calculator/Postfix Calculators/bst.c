/*
* bst.c, by Li Hansheng
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "bst.h"
#include "string.h"


typedef struct Node Node;

Node *search(Node *root, void* key, int tree_size, int loop_cont, int(*comparator)(void *, void *));
Node *newNode(void* key, void* value);
void printNode(FILE *fp, Node *tree, void(*display)(FILE *, void *, void *));
Node *insertNode(Node *tree, void* key, void* value, int(*comparator)(void *, void *));

struct Node
{
	void *key;
	void *value;
	struct Node *left;
	struct Node *right;
};

struct BST
{
	int size;
	struct Node *root;
	void(*display)(FILE *, void *, void *);
	int(*comparator)(void *, void *);
};

BST *newBST(void(*display)(FILE *, void *, void *), int(*comparator)(void *, void *))
{
	BST *bst = (BST*)malloc(sizeof(BST));
	assert(bst != 0);
	bst->display = display;
	bst->comparator = comparator;
	bst->root = NULL;
	bst->size = 0;
	return bst;
}

Node *newNode(void* key, void* value)
{
	Node *node = (Node*)malloc(sizeof(Node));
	assert(node != 0);
	node->key = key;
	node->value = value;
	node->left = node->right = NULL;
	return node;
}

void insertBST(BST *tree, void *key, void *value)
{
	if (tree->root == NULL)
	{
		//printf("Insert %s = %lf\n", getSTRING(key), getREAL(value));
		tree->root = (Node*)newNode(key, value);
	}
	else
	{
		tree->root = (Node* )insertNode(tree->root, key, value, tree->comparator);
	}
	tree->size++;
}

Node *insertNode(Node *tree, void* key, void* value, int(*comparator)(void *, void *))
{
	if (tree == NULL) {
			return newNode(key, value);
	}
	int compare = 0;

	compare = comparator(tree->key, key);
	if (compare > 0)//key was smaller, go left.
	{
		tree->left = insertNode(tree->left, key, value, comparator);
	}
	else if (compare < 0)//compare = 1, key was bigger, go right.
	{
		tree->right = insertNode(tree->right, key, value, comparator);
	}
	return tree;
}

/*
*The find method returns the value associated with 
*the given key.The method returns a null pointer if
*the key is not in the tree.
*/
void *findBST(BST *tree, void *key)
{
	return search(tree->root, key, tree->size, 0, tree->comparator);
}

Node *search(Node *root, void* key, int tree_size, int loop_cont, int(*comparator)(void *, void *))
{
	int compare = 0;
	compare = comparator(root->key, key);
	// Base Cases: root is null or key is present at root
	if (root == NULL || compare == 0)
		return root->value;
	if (loop_cont == tree_size - 1)
	{
		printf("variable %s was not declared\n", getSTRING(key));
		exit(0);
	}
	// Key is greater than root's key
	if (compare < 0)
		return search(root->right, key, tree_size, loop_cont++, comparator);
	else if (compare > 0)
	{
		// Key is smaller than root's key
		return search(root->left, key, tree_size, loop_cont++, comparator);
	}
	return root;
}

int sizeBST(BST *tree)
{
	return tree->size;
}

void displayBST(FILE *fp, BST *tree)
{
	if (tree->size == 0)
	{
		printf("[]");
		return;
	}
	printNode(fp, tree->root,tree->display);
}

void printNode(FILE *fp, Node *tree, void(*display)(FILE *, void *, void *))
{
	if (tree == NULL)
	{
		return;
	}
	printf("[");
	printNode(fp, tree->left, display);
	if (tree->left != NULL)
		printf(" ");
	display(fp, tree->key, tree->value);
	if (tree->right != NULL)
		printf(" ");
	printNode(fp, tree->right, display);
	printf("]");

}

