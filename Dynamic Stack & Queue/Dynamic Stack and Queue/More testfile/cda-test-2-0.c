#include <stdio.h>
#include <stdlib.h>
#include "cda.h"
#include "integer.h"
#include "real.h"
#include "string.h"
extern long random(void);
extern void srandom(unsigned int seed);

int
main(void)
    {
    printf("CDA tester: 2,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-2-0.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAfront(d,newINTEGER(893));
    insertCDAfront(d,newINTEGER(818));
    insertCDAfront(d,newINTEGER(215));
    insertCDAfront(d,newINTEGER(336));
    insertCDAfront(d,newINTEGER(366));
    displayCDA(stdout,d);
    printf("\n");
    return 0;
    }
