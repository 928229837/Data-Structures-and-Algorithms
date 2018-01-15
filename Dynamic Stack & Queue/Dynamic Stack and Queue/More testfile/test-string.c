/*
* string tester, by Li Hansheng
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "string.h"
#include "stack.h"
#include "da.h"



int
main(int argc, char **argv)

{

	if (argc != 1)

	{

		fprintf(stderr, "usage: %s\n", argv[0]);

		exit(1);

	}


	printf("string tester, version 1\n");

	STRING *x = newSTRING("ABC");

	printf("x is %s\n", getSTRING(x));

	setSTRING(x, "QWE");
	printf("x is now ");

	displaySTRING(stdout, x);

	printf("\n");


	return 0;

}
