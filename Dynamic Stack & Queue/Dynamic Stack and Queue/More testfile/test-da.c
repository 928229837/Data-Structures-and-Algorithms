/*
 * da tester, by Li Hansheng
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "integer.h"
#include "da.h"

int
main(int argc,char **argv)
    {
    if (argc != 1) { fprintf(stderr,"usage: %s\n",argv[0]); exit(1); }

    printf("da tester, version 1\n");
	DA *item = newDA(displayINTEGER);
	insertDA(item, newINTEGER(0));
	insertDA(item, newINTEGER(1));
	insertDA(item, newINTEGER(2));
	insertDA(item, newINTEGER(3));
	insertDA(item, newINTEGER(4));
	insertDA(item, newINTEGER(5));
	insertDA(item, newINTEGER(6));
	insertDA(item, newINTEGER(7));
	insertDA(item, newINTEGER(8));
	insertDA(item, newINTEGER(9));
	insertDA(item, newINTEGER(99));
	insertDA(item, newINTEGER(98));
	insertDA(item, newINTEGER(97));
	insertDA(item, newINTEGER(96));
	insertDA(item, newINTEGER(95));
	insertDA(item, newINTEGER(94));
	visualizeDA(stdout, item);
	displayDA(stdout, item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	removeDA(item);
	visualizeDA(stdout, item);
	displayDA(stdout, item);
	void *remove = removeDA(item);
	printf("Next removed item: ");
	displayINTEGER(stdout, remove);
	printf("\n");
	visualizeDA(stdout, item);
	displayDA(stdout, item);
	DA *itemOld = newDA(displayINTEGER);
	insertDA(itemOld, newINTEGER(21));
	insertDA(itemOld, newINTEGER(22));
	insertDA(itemOld, newINTEGER(23));
	insertDA(itemOld, newINTEGER(24));
	insertDA(itemOld, newINTEGER(25));
	insertDA(itemOld, newINTEGER(26));
	insertDA(itemOld, newINTEGER(27));
	insertDA(itemOld, newINTEGER(28));
	insertDA(itemOld, newINTEGER(29));
	insertDA(item, newINTEGER(0));
	insertDA(item, newINTEGER(1));
	insertDA(item, newINTEGER(2));
	insertDA(item, newINTEGER(3));
	insertDA(item, newINTEGER(4));
	insertDA(item, newINTEGER(5));
	insertDA(item, newINTEGER(6));
	insertDA(item, newINTEGER(7));
	visualizeDA(stdout, item);
	visualizeDA(stdout, itemOld);
	unionDA(item,itemOld);
	visualizeDA(stdout, item);
	visualizeDA(stdout, itemOld);

    return 0;
    }