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
    printf("DA tester: 2,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-2-0.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(893));
    insertDA(d,newINTEGER(818));
    insertDA(d,newINTEGER(215));
    insertDA(d,newINTEGER(336));
    insertDA(d,newINTEGER(366));
    displayDA(stdout,d);
    printf("\n");
    return 0;
    }
