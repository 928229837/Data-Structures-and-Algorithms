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
    printf("QUEUE tester: 2,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-2-2.c\n");
    printf("\noutput:\n\n");
    QUEUE *d = newQUEUE(displaySTRING);
    enqueue(d,newSTRING("FTW"));
    enqueue(d,newSTRING("JGY"));
    enqueue(d,newSTRING("TQH"));
    enqueue(d,newSTRING("WHJ"));
    enqueue(d,newSTRING("QTZ"));
    enqueue(d,newSTRING("GZY"));
    enqueue(d,newSTRING("JDB"));
    displayQUEUE(stdout,d);
    printf("\n");
    return 0;
    }
