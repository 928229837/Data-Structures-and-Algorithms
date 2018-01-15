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
    printf("DA tester: 2,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-2-2.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displaySTRING);
    insertDA(d,newSTRING("FTW"));
    insertDA(d,newSTRING("JGY"));
    insertDA(d,newSTRING("TQH"));
    insertDA(d,newSTRING("WHJ"));
    insertDA(d,newSTRING("QTZ"));
    insertDA(d,newSTRING("GZY"));
    insertDA(d,newSTRING("JDB"));
    visualizeDA(stdout,d);
    printf("\n");
    return 0;
    }
