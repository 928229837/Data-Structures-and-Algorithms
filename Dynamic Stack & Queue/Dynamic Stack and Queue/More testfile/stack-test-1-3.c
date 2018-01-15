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
    printf("STACK tester: 1,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-1-3.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displayINTEGER);
    void *p;
    printf("pushing items onto stack d\n");
    push(d,newINTEGER(807));
    push(d,newINTEGER(89));
    push(d,newINTEGER(656));
    push(d,newINTEGER(991));
    push(d,newINTEGER(44));
    push(d,newINTEGER(921));
    push(d,newINTEGER(365));
    push(d,newINTEGER(880));
    push(d,newINTEGER(1));
    push(d,newINTEGER(303));
    push(d,newINTEGER(981));
    push(d,newINTEGER(948));
    push(d,newINTEGER(28));
    push(d,newINTEGER(419));
    push(d,newINTEGER(894));
    push(d,newINTEGER(318));
    push(d,newINTEGER(701));
    push(d,newINTEGER(642));
    push(d,newINTEGER(688));
    push(d,newINTEGER(928));
    push(d,newINTEGER(823));
    push(d,newINTEGER(619));
    push(d,newINTEGER(993));
    push(d,newINTEGER(517));
    push(d,newINTEGER(567));
    push(d,newINTEGER(97));
    push(d,newINTEGER(532));
    push(d,newINTEGER(135));
    push(d,newINTEGER(72));
    push(d,newINTEGER(877));
    push(d,newINTEGER(510));
    push(d,newINTEGER(879));
    push(d,newINTEGER(318));
    push(d,newINTEGER(519));
    push(d,newINTEGER(223));
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
    printf("stack d: ");
    displaySTACK(stdout,d);
    printf("\n");
    printf("popping the last item from stack d\n");
    p = pop(d);
    printf("stack d: ");
    displaySTACK(stdout,d);
    printf("\n");
    printf("pushing one item into stack d\n");
    push(d,newINTEGER(715));
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
