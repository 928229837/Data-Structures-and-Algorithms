/*
* Integer tester, by Li Hansheng
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "real.h"

void Fatal(char *, ...);

int
main(int argc, char **argv)
{
	if (argc != 1) Fatal("usage: %s\n", argv[0]);

	printf("REAL tester, version 1\n");
	REAL *x = newREAL(2.2);
	printf("x is %f\n", getREAL(x));
	setREAL(x, 3.3);
	printf("x is now ");
	displayREAL(stdout, x);
	printf("\n");
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
