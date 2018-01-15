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
    printf("QUEUE tester: 1,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-1-2.c\n");
    printf("\noutput:\n\n");
    QUEUE *d = newQUEUE(displaySTRING);
    enqueue(d,newSTRING("XLI"));
    enqueue(d,newSTRING("QFG"));
    enqueue(d,newSTRING("FWM"));
    enqueue(d,newSTRING("IBP"));
    enqueue(d,newSTRING("ORE"));
    enqueue(d,newSTRING("HEC"));
    enqueue(d,newSTRING("DGY"));
    enqueue(d,newSTRING("TAY"));
    enqueue(d,newSTRING("BOQ"));
    displayQUEUE(stdout,d);
    printf("\n");
    return 0;
    }
