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
    printf("STACK tester: 1,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-1-0.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displayINTEGER);
    push(d,newINTEGER(379));
    push(d,newINTEGER(401));
    push(d,newINTEGER(125));
    push(d,newINTEGER(870));
    push(d,newINTEGER(80));
    push(d,newINTEGER(212));
    displaySTACK(stdout,d);
    printf("\n");
    return 0;
    }
