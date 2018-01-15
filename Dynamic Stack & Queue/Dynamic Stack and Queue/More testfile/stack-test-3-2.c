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
    printf("STACK tester: 3,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-3-2.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displaySTRING);
    push(d,newSTRING("SXL"));
    push(d,newSTRING("ILQ"));
    push(d,newSTRING("CRH"));
    push(d,newSTRING("RNW"));
    push(d,newSTRING("UCR"));
    displaySTACK(stdout,d);
    printf("\n");
    return 0;
    }
