#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "integer.h"
#include "real.h"
#include "string.h"
extern long random(void);
extern void srandom(unsigned int seed);

int
main(void)
    {
    printf("STACK tester: 2,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-2-2.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displaySTRING);
    push(d,newSTRING("FTW"));
    push(d,newSTRING("JGY"));
    push(d,newSTRING("TQH"));
    push(d,newSTRING("WHJ"));
    push(d,newSTRING("QTZ"));
    push(d,newSTRING("GZY"));
    push(d,newSTRING("JDB"));
    displaySTACK(stdout,d);
    printf("\n");
    return 0;
    }
