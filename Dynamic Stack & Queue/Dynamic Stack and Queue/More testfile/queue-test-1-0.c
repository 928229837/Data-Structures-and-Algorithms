#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "integer.h"
#include "real.h"
#include "string.h"
extern long random(void);
extern void srandom(unsigned int seed);

int
main(void)
    {
    printf("QUEUE tester: 1,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-1-0.c\n");
    printf("\noutput:\n\n");
    QUEUE *d = newQUEUE(displayINTEGER);
    enqueue(d,newINTEGER(379));
    enqueue(d,newINTEGER(401));
    enqueue(d,newINTEGER(125));
    enqueue(d,newINTEGER(870));
    enqueue(d,newINTEGER(80));
    enqueue(d,newINTEGER(212));
    displayQUEUE(stdout,d);
    printf("\n");
    return 0;
    }
