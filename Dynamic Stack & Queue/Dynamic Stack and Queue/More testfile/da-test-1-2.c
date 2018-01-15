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
    printf("DA tester: 1,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-1-2.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displaySTRING);
    insertDA(d,newSTRING("XLI"));
    insertDA(d,newSTRING("QFG"));
    insertDA(d,newSTRING("FWM"));
    insertDA(d,newSTRING("IBP"));
    insertDA(d,newSTRING("ORE"));
    insertDA(d,newSTRING("HEC"));
    insertDA(d,newSTRING("DGY"));
    insertDA(d,newSTRING("TAY"));
    insertDA(d,newSTRING("BOQ"));
    visualizeDA(stdout,d);
    printf("\n");
    return 0;
    }
