/*
* trees.c, by Li Hansheng
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "gt.h"
#include "rbt.h"
#include "scanner.h"
#include "string.h"

void Fatal(char *, ...);
char* getWords(FILE* fp);
void displayNode(FILE *fp, void *value);
int comparator(void *nodeA, void *nodeB);

int main(int argc, char **argv)
{
	int gt = 0;
	int rbt = 0;
	if (argc <= 1) Fatal("%d arguments!\n", argc - 1);

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

	//read command and file
	//-g (green tree) and -r (red-black tree)
	int sp = 0;
	//sp was for check -g/-r exist or not.
	//If exist sp = 1, not = 0;

	if (!strcmp(argv[1], "-r"))
	{
		rbt = 1;
		sp = 1;
	}
	else if (!strcmp(argv[1], "-g"))
	{
		sp = 1;
		gt = 1;
	}
	else
		rbt = 1;

	//Example: trees -r corpus commands outputfile

	//To open corpus file, should be argv[1 + sp]
	FILE *corpus;
	corpus = fopen(argv[1 + sp], "r");
	if (corpus == NULL)
	{
		printf("Can not open corpus file or it was empty.\n");
		exit(0);
	}

	//To open command file, should be argv[2 + sp]
	FILE *command;
	command = fopen(argv[2 + sp], "r");
	if (command == NULL)
	{
		printf("Can not open command file or it was empty. \n");
		exit(0);
	}

	//To check output file, should be argv[3 + sp]
	if (argc - sp == 4)
	{
		FILE *output;
		output = freopen(argv[3 + sp], "w", stdout);
		if (output == NULL)
		{
			printf("Can not open output file or it was empty. \n");
			exit(0);
		}
	}

	char* word;
	word = getWords(corpus);

	/*************************Green Tree*************************/
	if (gt == 1)
	{
		GT *gt = newGT(displayNode, comparator);
		while (word != NULL)
		{
			if (strcmp(word, ""))
				insertGT(gt, newSTRING(word));
			word = getWords(corpus);
		}

		word = getWords(command);
		while (word != NULL)
		{
			if (!strcmp(word, "i"))//insert word or phrase W into the tree
				insertGT(gt, newSTRING(getWords(command)));
			else if (!strcmp(word, "d"))//delete word or phrase W from the tree
				deleteGT(gt, newSTRING(getWords(command)));
			else if (!strcmp(word, "f"))//report the frequency of word or phrase W
			{
				word = getWords(command);
				int a = findGT(gt, newSTRING(word));
				printf("Frequency of %s: %d\n", word, a);
			}
			else if (!strcmp(word, "s"))//show the tree
				displayGT(stdout, gt);
			else if (!strcmp(word, "r"))//report statistics
				statisticsGT(stdout, gt);
			word = getWords(command);
		}
	}
	/*************************Red Black Tree*************************/
	else if (rbt == 1)
	{
		RBT *rbt = newRBT(displayNode, comparator);
		STRING* value;
		while (word != NULL)
		{
			value = newSTRING(word);
			if (strcmp(word, ""))
				insertRBT(rbt, value);
			word = getWords(corpus);
		}
		word = getWords(command);

		while (word != NULL)
		{
			if (!strcmp(word, "i"))//insert word or phrase W into the tree
				insertRBT(rbt, newSTRING(getWords(command)));
			else if (!strcmp(word, "d"))//delete word or phrase W from the tree
				deleteRBT(rbt, newSTRING(getWords(command)));
			else if (!strcmp(word, "f"))//report the frequency of word or phrase W
			{
				word = getWords(command);
				int a = findRBT(rbt, newSTRING(word));
				printf("Frequency of %s: %d\n", word, a);
			}
			else if (!strcmp(word, "s"))//show the tree
				displayRBT(stdout, rbt);
			else if (!strcmp(word, "r"))//report statistics
				statisticsRBT(stdout, rbt);
			word = getWords(command);
		}
	}
	else
	{
		printf("ERROR: gt & rbt can't both !=  1");
		exit(1);
	}

	return 0;
}

void Fatal(char *fmt, ...)
{
	va_list ap;
	fprintf(stderr, "An error occured: ");
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	exit(-1);
}

char* getWords(FILE* fp)
{
	char* word;
	word = readWords(fp);
	while (word != NULL)
	{
		return word;
	}
	return NULL;
}

void displayNode(FILE *fp, void *value)
{
	fprintf(fp, "%s", getSTRING(value));
}

int comparator(void *nodeA, void *nodeB)
{   // B smaller ->  1;
	// B bigger  -> -1; 
	// A B equal ->  0; 
	return strcmp(getSTRING(nodeA), getSTRING(nodeB));
}