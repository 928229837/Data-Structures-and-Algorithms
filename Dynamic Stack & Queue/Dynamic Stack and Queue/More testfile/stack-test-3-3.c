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
    printf("STACK tester: 3,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-3-3.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displayINTEGER);
    void *p;
    printf("pushing items onto stack d\n");
    push(d,newINTEGER(939));
    push(d,newINTEGER(39));
    push(d,newINTEGER(446));
    push(d,newINTEGER(942));
    push(d,newINTEGER(904));
    push(d,newINTEGER(677));
    push(d,newINTEGER(350));
    push(d,newINTEGER(55));
    push(d,newINTEGER(631));
    push(d,newINTEGER(36));
    push(d,newINTEGER(232));
    push(d,newINTEGER(848));
    push(d,newINTEGER(236));
    push(d,newINTEGER(984));
    push(d,newINTEGER(827));
    push(d,newINTEGER(101));
    push(d,newINTEGER(924));
    push(d,newINTEGER(995));
    push(d,newINTEGER(399));
    push(d,newINTEGER(822));
    push(d,newINTEGER(962));
    push(d,newINTEGER(60));
    push(d,newINTEGER(852));
    push(d,newINTEGER(300));
    push(d,newINTEGER(573));
    push(d,newINTEGER(545));
    push(d,newINTEGER(173));
    push(d,newINTEGER(618));
    push(d,newINTEGER(329));
    push(d,newINTEGER(451));
    push(d,newINTEGER(94));
    push(d,newINTEGER(269));
    push(d,newINTEGER(842));
    push(d,newINTEGER(892));
    push(d,newINTEGER(563));
    push(d,newINTEGER(746));
    printf("stack d: ");
    displaySTACK(stdout,d);
    printf("\n");
    printf("peeking into stack d\n");
    p = peekSTACK(d);
    printf("the next element to come off the stack: ");
    displayINTEGER(stdout,p);
    printf("\n");
    printf("popping all but one item from stack d\n");
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    printf("stack d: ");
    displaySTACK(stdout,d);
    printf("\n");
    printf("popping the last item from stack d\n");
    p = pop(d);
    printf("stack d: ");
    displaySTACK(stdout,d);
    printf("\n");
    printf("pushing one item into stack d\n");
    push(d,newINTEGER(922));
    printf("popping that item\n");
    p = pop(d);
    printf("stack d: ");
    displaySTACK(stdout,d);
    printf("\n");
    printf("last element popped: ");
    displayINTEGER(stdout,p);
    printf("\n");
    return 0;
    }
