/*
* matilda.c, by Li Hansheng
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "scanner.h"
#include "real.h"
#include "string.h"
#include "bst.h"
#include "queue.h"
#include "process.h"
#include "integer.h"


void Fatal(char *, ...);
void displayNode(FILE *fp, void *key, void *value);
int comparator(void *nodeA, void *nodeB);

int
main(int argc, char **argv)
{
	if (argc == 1) Fatal("%d arguments!\n", argc - 1);

	//-v give author's name and exit
	int i = 0;
	for (i = 0; i< argc - 1; i++)
	{
		if (!strcmp(argv[i + 1], "-v"))
		{
			printf("Hansheng Li\n");
			exit(0);
		}
	}

	FILE *fp;
	fp = fopen(argv[argc - 1], "r");
	if (fp == NULL)
	{
		printf("Cannot open file or file was empty. \n");
		exit(0);
	}

	//-i print the original input to evaluating the expression
	for (i = 0; i< argc - 1; i++)
	{
		if (!strcmp(argv[i + 1], "-i"))
		{
			char* temp;
			temp = readToken(fp);
			while (temp != NULL)
			{
				if (!strcmp(temp, ";"))
				{
					printf(";\n");
				}
				else
				{
					printf("%s ", temp);
				}
				temp = readToken(fp);
			}
			fclose(fp);
		}
	}

	////Store value to BST & Stack & Queue
	BST *tree = newBST(displayNode, comparator);
	fp = fopen(argv[argc - 1], "r");
	char* token;
	char* a = "(";
	STRING* key;
	REAL* value;
	QUEUE *infix = newQUEUE(displaySTRING);
	QUEUE *postfix = newQUEUE(displaySTRING);
	key = newSTRING(a);
	enqueue(infix, key);
	token = readToken(fp);
	while (token != NULL)
	{
		if (!strcmp(token, "var"))
		{
			key = newSTRING(readToken(fp));
			readToken(fp);//skip "="
			value = newREAL(readReal(fp));
			insertBST(tree, key, value);
			readToken(fp);//skip ";"
		}
		else if (strcmp(token, ";"))//if token isn't ";"
		{
			key = newSTRING(token);
			enqueue(infix, key);
		}
		token = readToken(fp);//read after ";"
	}
	a = ")";
	key = newSTRING(a);
	enqueue(infix, key);
	InfixToPostfix(infix, postfix);
	fclose(fp);

	//-p print the postfix conversion of
	//the last infix expression
	for (i = 0; i< argc - 1; i++)
	{
		if (!strcmp(argv[i + 1], "-p"))
		{
			displayQUEUE(stdout, postfix);
			printf("\n");
		}
	}


	//-b print the BST holding variable values
	//before evaluating the expression
	for (i = 0; i< argc - 1; i++)
	{
		if (!strcmp(argv[i + 1], "-b"))
		{
			displayBST(stdout, tree);
			printf("\n");
		}
	}

	//calculate
	printf("%lf\n",calculate(postfix, tree));
	return 0;
}

void
Fatal(char *fmt, ...)
{
	va_list ap;
	fprintf(stderr, "An error occured: ");
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	exit(-1);
}

void displayNode(FILE *fp, void *key, void *value)
{
	fprintf(fp, "%s", getSTRING((STRING *)key));
	printf("=");
	fprintf(fp, "%f", getREAL(value));
}

int comparator(void *nodeA, void *nodeB)
{   // B smaller ->  1;
	// B bigger  -> -1; 
	// A B equal ->  0; 
	return strcmp(getSTRING(nodeA), getSTRING(nodeB));
}
