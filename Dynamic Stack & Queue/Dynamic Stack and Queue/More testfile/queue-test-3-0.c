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
    printf("QUEUE tester: 3,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-3-0.c\n");
    printf("\noutput:\n\n");
    QUEUE *d = newQUEUE(displayINTEGER);
    enqueue(d,newINTEGER(145));
    enqueue(d,newINTEGER(163));
    enqueue(d,newINTEGER(995));
    enqueue(d,newINTEGER(469));
    enqueue(d,newINTEGER(365));
    enqueue(d,newINTEGER(933));
    enqueue(d,newINTEGER(807));
    enqueue(d,newINTEGER(129));
    displayQUEUE(stdout,d);
    printf("\n");
    return 0;
    }
