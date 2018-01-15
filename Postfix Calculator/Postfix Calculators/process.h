#ifndef __PROCESS_INCLUDED__
#define __PROCESS_INCLUDED__

#include <stdio.h>

/* define function that is used to determine whether any symbol is 
* operator or not (that is symbol is operand).
* this fucntion returns 1 if symbol is opreator else return 0 */
int is_operator(char* symbol);

/* define fucntion that is used to assign precendence to operator.
* Here ^ denotes exponent operator.
* In this fucntion we assume that higher integer value
* means higher precendence */
int precedence(char symbol);
int check(char* s);
double getNum(int k, BST* tree, void* key, char* string);
double calculate(QUEUE *postfix, BST* tree);


void InfixToPostfix(QUEUE *infix, QUEUE *postfix);




#endif