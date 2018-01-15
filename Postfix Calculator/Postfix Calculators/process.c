/*
* process.c, by Li Hansheng
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "real.h"
#include "string.h"
#include "bst.h"
#include "queue.h"
#include "stack.h"
#include "process.h"

double calculate(QUEUE *postfix, BST* tree)
{

	int i = 0;
	int k = 0;
	double a, b;
	double result = 0;
	STACK *stack = newSTACK(displaySTRING);
	void* key;
	char* string;
	int size = sizeQUEUE(postfix);
	for (i = 0; i < size; i++)
	{
		key = dequeue(postfix);
		string = getSTRING(key);
		k = check(string);
		if (k == 0)
		{
			a = atof(string);
			push(stack, newREAL(a));
		}
		else if (k == 1)
		{
			a = getREAL(findBST(tree, key));
			push(stack, newREAL(a));
		}
		else
		{
			a = getREAL(pop(stack));
			b = getREAL(pop(stack));
			switch (k)
			{
			case 2:// +
				result = b + a;
				break;
			case 3:// -
				result = b - a;
				break;
			case 4:// *
				result = b * a;
				break;
			case 5:// /
				result = b / a;
				break;
			case 6:// ^
				result = pow(b, a);
				break;
			case 7:// %
				result = fmod(b, a);
				break;
			default:
				printf("Error: unknown command. Code : %d\n", k);
				break;
			}
		push(stack, newREAL(result));
		}
		//printf("real stack : %d\n", sizeSTACK(real));
		if (i == size - 1)
		{
			result = getREAL(pop(stack));
			//sscanf(string, "%lf", &result);
		}
	}
	return result;
}

double getNum(int k, BST* tree, void* key, char* string)
{
	double a;
	if (k == 0) //is a number
	{
		a = atof(string);
	}
	else // is a bst node
	{
		a = getREAL(findBST(tree, key));
	}
	return a;
}

int check(char* s)
{
	if (isdigit(s[0]))
		return 0;// check = 0 when is digit.
	if (isalpha(s[0]))
		return 1;// check = 1 when is alpha.
	if (s[0] == '+')
	{
		if (s [1] == '\0')
		{
			return 2;// 2 for +
		}
		return 0;
	}
	if (s[0] == '-')
	{
		if (s[1] == '\0')
		{
			return 3;// 3 for -
		}
		return 0;
	}
	if (s[0] == '*')
		return 4;// 4 for '*'
	if (s[0] == '/')
		return 5;// 5 for '/'
	if (s[0] == '^')
		return 6;// 5 for '/'
	if (s[0] == '%')
		return 7;// 5 for '/'
	printf("Unknow string\n");
	return 7;//Error
}

void InfixToPostfix(QUEUE *infix , QUEUE *postfix)
{
	int i = 0;
	int size = sizeQUEUE(infix);
	char* item;
	char* x;
	STACK *stack = newSTACK(displaySTRING);

	item = getSTRING(dequeue(infix));         /* initialize before loop*/

	for (i = 0; i < size ; i++)       /* run loop till end of infix expression */
	{
		if (item[0] == '(')
		{
			push(stack, newSTRING(item));
		}
		else if (isdigit(item[0]) || isalpha(item[0]) || isdigit(item[1]) || isalpha(item[1]))
		{
			enqueue(postfix, newSTRING(item));
		}
		else if (is_operator(item) == 1)        /* means symbol is operator */
		{
			x = getSTRING(pop(stack));
			while (is_operator(x) == 1 && precedence(x[0]) >= precedence(item[0]))
			{
				enqueue(postfix, newSTRING(x));
				x = getSTRING(pop(stack));
			}
			push(stack, newSTRING(x));
			/* because just above while loop will terminate we have
			oppped one extra item
			for which condition fails and loop terminates, so that one*/

			push(stack, newSTRING(item));                 /* push current oprerator symbol onto stack */
		}
		else if (item[0] == ')')         /* if current symbol is ')' then */
		{
			x = getSTRING(pop(stack));                   /* pop and keep popping until */
			while (x[0] != '(')                /* '(' encounterd */
			{
				enqueue(postfix, newSTRING(x));
				x = getSTRING(pop(stack));
			}
		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
		  operator */
			printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		if (i < size - 1)
		{
			item = getSTRING(dequeue(infix));
		}
	} /* while loop ends here */
}

int is_operator(char* symbol)
{
	char a = symbol[0];
	if ((a == '^' || a == '*' || a == '/' || a == '+' || a == '-' || a == '%'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int precedence(char symbol)
{
	if (symbol == '^')/* exponent operator, highest precedence*/
	{
		return(6);
	}
	else if (symbol == '%')
	{
		return(5);
	}
	else if (symbol == '/')
	{
		return(4);
	}
	else if (symbol == '*')
	{
		return(3);
	}
	else if (symbol == '-')
	{
		return(2);
	}
	else if (symbol == '+')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}




