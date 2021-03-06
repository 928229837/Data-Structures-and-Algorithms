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
    printf("QUEUE tester: 1,6\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-1-6.c\n");
    printf("\noutput:\n\n");
    int count = 0;
    srandom(1007);
    QUEUE *d = newQUEUE(displayINTEGER);
    printf("doing a bunch of enqueues\n");
    int i;
    for (i = 0; i < 16661; ++i)
        {
        enqueue(d,newINTEGER(random()%1000));
        ++count;
        }
    printf("randomly doing a bunch of enqueues and dequeues\n");
    void *p;
    for (i = 0; i < 16661; ++i)
        {
        if (random() % 2 == 0)
            {
            enqueue(d,newINTEGER(random()%1000));
            ++count;
            }
        else if (count > 0)
            {
            p = dequeue(d);
            --count;
            }
        }
    printf("doing a bunch of dequeues\n");
    while (count > 10)
        {
        dequeue(d);
        --count;
        }
    printf("queue d:");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("the last element dequeued: ");
    displayINTEGER(stdout,p);
    printf("\n");
    return 0;
    }
