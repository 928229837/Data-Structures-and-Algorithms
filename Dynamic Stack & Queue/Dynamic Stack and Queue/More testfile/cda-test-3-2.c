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
    printf("CDA tester: 3,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-3-2.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displaySTRING);
    insertCDAfront(d,newSTRING("SXL"));
    insertCDAfront(d,newSTRING("ILQ"));
    insertCDAfront(d,newSTRING("CRH"));
    insertCDAfront(d,newSTRING("RNW"));
    insertCDAfront(d,newSTRING("UCR"));
    visualizeCDA(stdout,d);
    printf("\n");
    return 0;
    }
