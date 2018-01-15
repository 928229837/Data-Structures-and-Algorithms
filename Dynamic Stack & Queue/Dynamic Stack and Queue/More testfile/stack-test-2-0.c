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
    printf("STACK tester: 2,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-2-0.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displayINTEGER);
    push(d,newINTEGER(893));
    push(d,newINTEGER(818));
    push(d,newINTEGER(215));
    push(d,newINTEGER(336));
    push(d,newINTEGER(366));
    displaySTACK(stdout,d);
    printf("\n");
    return 0;
    }
