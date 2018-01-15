#include <stdio.h>
#include <stdlib.h>
#include "da.h"
#include "integer.h"
#include "real.h"
#include "string.h"
extern long random(void);
extern void srandom(unsigned int seed);

int
main(void)
    {
    printf("DA tester: 1,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-1-0.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(379));
    insertDA(d,newINTEGER(401));
    insertDA(d,newINTEGER(125));
    insertDA(d,newINTEGER(870));
    insertDA(d,newINTEGER(80));
    insertDA(d,newINTEGER(212));
    displayDA(stdout,d);
    printf("\n");
    return 0;
    }
