/*
* stack tester, by Li Hansheng
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "integer.h"
#include "stack.h"
#include "da.h"

int
main(int argc, char **argv)
{
	if (argc != 1)
	{
		fprintf(stderr, "usage: %s\n", argv[0]); exit(1);
	}
	printf("stack tester, version 1\n");

	STACK *items = newSTACK(displayINTEGER);
	push(items, newINTEGER(1));
	push(items, newINTEGER(2));
	push(items, newINTEGER(3));
	push(items, newINTEGER(4));
	push(items, newINTEGER(5));
	push(items, newINTEGER(6));
	push(items, newINTEGER(7));
	push(items, newINTEGER(8));
	
	printf("\n\nsize: %d\n\n", sizeSTACK(items));
	displaySTACK(stdout, items);
	visualizeSTACK(stdout, items);

	return 0;
}
