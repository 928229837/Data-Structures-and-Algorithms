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
    printf("STACK tester: 1,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-1-2.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displaySTRING);
    push(d,newSTRING("XLI"));
    push(d,newSTRING("QFG"));
    push(d,newSTRING("FWM"));
    push(d,newSTRING("IBP"));
    push(d,newSTRING("ORE"));
    push(d,newSTRING("HEC"));
    push(d,newSTRING("DGY"));
    push(d,newSTRING("TAY"));
    push(d,newSTRING("BOQ"));
    displaySTACK(stdout,d);
    printf("\n");
    return 0;
    }
