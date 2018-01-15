#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "integer.h"
#include "cda.h"

int main(void)
{
	printf("Hello\n\n");
	CDA *items = newCDA(displayINTEGER);
	int i = 0;
	printf("\n");
	for (i = 1; i < 10; i++)
	{
		insertCDAfront(items, newINTEGER(i));
	}
	
	CDA *itemsNew = newCDA(displayINTEGER);
	for (i = 20; i < 30; i++)
	{
		insertCDAfront(itemsNew, newINTEGER(i));
	}

	printf("Old: ");
	visualizeCDA(stdout, items);
	printf("\n");

	printf("New: ");
	visualizeCDA(stdout, itemsNew);
	printf("\n");

	unionCDA(items, itemsNew);

	printf("Old: ");
	visualizeCDA(stdout, items);
	printf("\n");

	printf("New: ");
	visualizeCDA(stdout, itemsNew);
	printf("\n");

	for (i = 0; i < 10; i++)
	{
		displayINTEGER(stdout, getCDA(items, i));
		printf("\n");
	}
	
	visualizeCDA(stdout, items);
	printf("\n");
	//displayINTEGER(stdout, setCDA(items, -1, newINTEGER(999)));
	setCDA(items, -1, newINTEGER(999));
	printf("\n");
	visualizeCDA(stdout, items);
	printf("\n");

	printf("display function: ");
	displayCDA(stdout, items);
	printf("\n");

	void **p;
	int size = sizeCDA(items);
	p = extractCDA(items);
	printf("Print out items (should be empty) :");
	visualizeCDA(stdout, items);
	printf("\n");
	printf("p : ");
	for (i = 0; i < size; i++)
	{
		displayINTEGER(stdout, p[i]);
		printf(",");
	}
	printf("\n");

	/*
	for (i = 0; i < 10; i++)
	{
		insertCDAfront(items, newINTEGER(i));
	}

	visualizeCDA(stdout, items);
	printf("\n");



	for (i = 50; i > 40; i--)
	{
		insertCDAback(items, newINTEGER(1));
	}

	visualizeCDA(stdout, items);
	printf("\n");

	insertCDAfront(items, newINTEGER(99));
	insertCDAfront(items, newINTEGER(98));
	insertCDAfront(items, newINTEGER(97));

	visualizeCDA(stdout, items);
	printf("\n");

	insertCDAback(items, newINTEGER(77));
	insertCDAback(items, newINTEGER(78));
	insertCDAback(items, newINTEGER(79));
	visualizeCDA(stdout, items);
	printf("\n");


	for (i = 0; i < 25; i++)
	{
		removeCDAback(items);
	}
	*/

	/*
	insertCDAback(items, newINTEGER(79));
	insertCDAback(items, newINTEGER(79));
	insertCDAback(items, newINTEGER(79));
	insertCDAback(items, newINTEGER(79));
	removeCDAback(items);
	removeCDAback(items);
	removeCDAback(items);
	removeCDAback(items);
	insertCDAback(items, newINTEGER(79));
	removeCDAback(items);
	*/

	/*
	visualizeCDA(stdout, items);
	printf("\n");
	for (i = 1; i < 10; i++)
	{
		insertCDAfront(items, newINTEGER(i));
		insertCDAback(items, newINTEGER(90-i));
		visualizeCDA(stdout, items);
		printf("\n");
	}
 

	for (i = 0; i < 15; i++)
	{
		removeCDAfront(items);
		removeCDAback(items);
		visualizeCDA(stdout, items);
		printf("\n");
	}
	insertCDAfront(items, newINTEGER(5));
	removeCDAfront(items);
	visualizeCDA(stdout, items);
	printf("\n");
	*/



	///////////////////



	return 0;
}


