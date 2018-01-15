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
    printf("QUEUE tester: 3,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-3-3.c\n");
    printf("\noutput:\n\n");
    QUEUE *d = newQUEUE(displayINTEGER);
    void *p;
    printf("enqueuing items onto queue d\n");
    enqueue(d,newINTEGER(939));
    enqueue(d,newINTEGER(39));
    enqueue(d,newINTEGER(446));
    enqueue(d,newINTEGER(942));
    enqueue(d,newINTEGER(904));
    enqueue(d,newINTEGER(677));
    enqueue(d,newINTEGER(350));
    enqueue(d,newINTEGER(55));
    enqueue(d,newINTEGER(631));
    enqueue(d,newINTEGER(36));
    enqueue(d,newINTEGER(232));
    enqueue(d,newINTEGER(848));
    enqueue(d,newINTEGER(236));
    enqueue(d,newINTEGER(984));
    enqueue(d,newINTEGER(827));
    enqueue(d,newINTEGER(101));
    enqueue(d,newINTEGER(924));
    enqueue(d,newINTEGER(995));
    enqueue(d,newINTEGER(399));
    enqueue(d,newINTEGER(822));
    enqueue(d,newINTEGER(962));
    enqueue(d,newINTEGER(60));
    enqueue(d,newINTEGER(852));
    enqueue(d,newINTEGER(300));
    enqueue(d,newINTEGER(573));
    enqueue(d,newINTEGER(545));
    enqueue(d,newINTEGER(173));
    enqueue(d,newINTEGER(618));
    enqueue(d,newINTEGER(329));
    enqueue(d,newINTEGER(451));
    enqueue(d,newINTEGER(94));
    enqueue(d,newINTEGER(269));
    enqueue(d,newINTEGER(842));
    enqueue(d,newINTEGER(892));
    enqueue(d,newINTEGER(563));
    enqueue(d,newINTEGER(746));
    printf("queue d: ");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("peeking into queue d\n");
    p = peekQUEUE(d);
    printf("the next element to come off the queue: ");
    displayINTEGER(stdout,p);
    printf("\n");
    printf("dequeuing all but one item from queue d\n");
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    printf("queue d: ");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("dequeuing the last item from queue d\n");
    p = dequeue(d);
    printf("queue d: ");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("enqueuing one item into queue d\n");
    enqueue(d,newINTEGER(922));
    printf("dequeuing that item\n");
    p = dequeue(d);
    printf("queue d: ");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("last element dequeued: ");
    displayINTEGER(stdout,p);
    printf("\n");
    return 0;
    }
