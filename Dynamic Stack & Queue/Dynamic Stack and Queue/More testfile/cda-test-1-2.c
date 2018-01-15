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
    printf("CDA tester: 1,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-1-2.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displaySTRING);
    insertCDAfront(d,newSTRING("XLI"));
    insertCDAfront(d,newSTRING("QFG"));
    insertCDAfront(d,newSTRING("FWM"));
    insertCDAfront(d,newSTRING("IBP"));
    insertCDAfront(d,newSTRING("ORE"));
    insertCDAfront(d,newSTRING("HEC"));
    insertCDAfront(d,newSTRING("DGY"));
    insertCDAfront(d,newSTRING("TAY"));
    insertCDAfront(d,newSTRING("BOQ"));
    visualizeCDA(stdout,d);
    printf("\n");
    return 0;
    }
