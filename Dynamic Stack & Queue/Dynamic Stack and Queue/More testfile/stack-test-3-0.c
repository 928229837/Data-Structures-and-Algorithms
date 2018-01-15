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
    printf("STACK tester: 3,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-3-0.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displayINTEGER);
    push(d,newINTEGER(145));
    push(d,newINTEGER(163));
    push(d,newINTEGER(995));
    push(d,newINTEGER(469));
    push(d,newINTEGER(365));
    push(d,newINTEGER(933));
    push(d,newINTEGER(807));
    push(d,newINTEGER(129));
    displaySTACK(stdout,d);
    printf("\n");
    return 0;
    }
