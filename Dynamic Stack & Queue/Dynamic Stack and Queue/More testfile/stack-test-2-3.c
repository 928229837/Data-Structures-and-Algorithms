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
    printf("STACK tester: 2,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-2-3.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displayINTEGER);
    void *p;
    printf("pushing items onto stack d\n");
    push(d,newINTEGER(856));
    push(d,newINTEGER(122));
    push(d,newINTEGER(271));
    push(d,newINTEGER(538));
    push(d,newINTEGER(303));
    push(d,newINTEGER(484));
    push(d,newINTEGER(939));
    push(d,newINTEGER(599));
    push(d,newINTEGER(190));
    push(d,newINTEGER(189));
    push(d,newINTEGER(361));
    push(d,newINTEGER(445));
    push(d,newINTEGER(178));
    push(d,newINTEGER(224));
    push(d,newINTEGER(168));
    push(d,newINTEGER(501));
    push(d,newINTEGER(668));
    push(d,newINTEGER(26));
    push(d,newINTEGER(537));
    push(d,newINTEGER(581));
    push(d,newINTEGER(44));
    push(d,newINTEGER(732));
    push(d,newINTEGER(469));
    push(d,newINTEGER(229));
    push(d,newINTEGER(660));
    push(d,newINTEGER(894));
    push(d,newINTEGER(364));
    push(d,newINTEGER(816));
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
    printf("stack d: ");
    displaySTACK(stdout,d);
    printf("\n");
    printf("popping the last item from stack d\n");
    p = pop(d);
    printf("stack d: ");
    displaySTACK(stdout,d);
    printf("\n");
    printf("pushing one item into stack d\n");
    push(d,newINTEGER(573));
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
