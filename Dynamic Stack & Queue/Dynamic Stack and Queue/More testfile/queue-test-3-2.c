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
    printf("QUEUE tester: 3,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-3-2.c\n");
    printf("\noutput:\n\n");
    QUEUE *d = newQUEUE(displaySTRING);
    enqueue(d,newSTRING("SXL"));
    enqueue(d,newSTRING("ILQ"));
    enqueue(d,newSTRING("CRH"));
    enqueue(d,newSTRING("RNW"));
    enqueue(d,newSTRING("UCR"));
    displayQUEUE(stdout,d);
    printf("\n");
    return 0;
    }
