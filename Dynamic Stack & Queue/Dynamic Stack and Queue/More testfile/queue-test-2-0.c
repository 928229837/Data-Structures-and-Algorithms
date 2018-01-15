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
    printf("QUEUE tester: 2,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-2-0.c\n");
    printf("\noutput:\n\n");
    QUEUE *d = newQUEUE(displayINTEGER);
    enqueue(d,newINTEGER(893));
    enqueue(d,newINTEGER(818));
    enqueue(d,newINTEGER(215));
    enqueue(d,newINTEGER(336));
    enqueue(d,newINTEGER(366));
    displayQUEUE(stdout,d);
    printf("\n");
    return 0;
    }
