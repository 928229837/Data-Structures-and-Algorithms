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
    printf("CDA tester: 3,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-3-0.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAfront(d,newINTEGER(145));
    insertCDAfront(d,newINTEGER(163));
    insertCDAfront(d,newINTEGER(995));
    insertCDAfront(d,newINTEGER(469));
    insertCDAfront(d,newINTEGER(365));
    insertCDAfront(d,newINTEGER(933));
    insertCDAfront(d,newINTEGER(807));
    insertCDAfront(d,newINTEGER(129));
    displayCDA(stdout,d);
    printf("\n");
    return 0;
    }
