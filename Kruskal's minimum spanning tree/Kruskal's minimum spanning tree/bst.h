#ifndef __BST_INCLUDED__
#define __BST_INCLUDED__

#include <stdio.h>

typedef struct bstnode BSTNODE;

extern void    *getBSTNODE(BSTNODE *n);
extern BSTNODE *getBSTNODEleft(BSTNODE *n);
extern BSTNODE *getBSTNODEright(BSTNODE *n);
extern BSTNODE *getBSTNODEparent(BSTNODE *n);
extern void    setBSTNODE(BSTNODE *n, void *value);
extern void    setBSTNODEleft(BSTNODE *n, BSTNODE *replacement);
extern void    setBSTNODEright(BSTNODE *n, BSTNODE *replacement);
extern void    setBSTNODEparent(BSTNODE *n, BSTNODE *replacement);

typedef struct bst BST;

extern BST *newBST(void(*display)(FILE *, void *), int(*comparator)(void *, void *), void(*swapper)(BSTNODE *, BSTNODE *));

extern int     sizeBST(BST *t);
extern void    displayBST(FILE *fp, BST *t);
extern void    statisticsBST(FILE *fp, BST *t);
extern void    pruneLeafBST(BST *t, BSTNODE *leaf);
extern void    setBSTroot(BST *t, BSTNODE *replacement);

extern BSTNODE *getBSTroot(BST *t);
extern BSTNODE *findBST(BST *t, void *value);
extern BSTNODE *deleteBST(BST *t, void *value);
extern BSTNODE *insertBST(BST *t, void *value);
extern BSTNODE *swapToLeafBST(BST *t, BSTNODE *node);

#endif