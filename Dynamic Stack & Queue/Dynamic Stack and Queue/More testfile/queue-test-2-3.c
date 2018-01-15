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
    printf("QUEUE tester: 2,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-2-3.c\n");
    printf("\noutput:\n\n");
    QUEUE *d = newQUEUE(displayINTEGER);
    void *p;
    printf("enqueuing items onto queue d\n");
    enqueue(d,newINTEGER(856));
    enqueue(d,newINTEGER(122));
    enqueue(d,newINTEGER(271));
    enqueue(d,newINTEGER(538));
    enqueue(d,newINTEGER(303));
    enqueue(d,newINTEGER(484));
    enqueue(d,newINTEGER(939));
    enqueue(d,newINTEGER(599));
    enqueue(d,newINTEGER(190));
    enqueue(d,newINTEGER(189));
    enqueue(d,newINTEGER(361));
    enqueue(d,newINTEGER(445));
    enqueue(d,newINTEGER(178));
    enqueue(d,newINTEGER(224));
    enqueue(d,newINTEGER(168));
    enqueue(d,newINTEGER(501));
    enqueue(d,newINTEGER(668));
    enqueue(d,newINTEGER(26));
    enqueue(d,newINTEGER(537));
    enqueue(d,newINTEGER(581));
    enqueue(d,newINTEGER(44));
    enqueue(d,newINTEGER(732));
    enqueue(d,newINTEGER(469));
    enqueue(d,newINTEGER(229));
    enqueue(d,newINTEGER(660));
    enqueue(d,newINTEGER(894));
    enqueue(d,newINTEGER(364));
    enqueue(d,newINTEGER(816));
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
    printf("queue d: ");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("dequeuing the last item from queue d\n");
    p = dequeue(d);
    printf("queue d: ");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("enqueuing one item into queue d\n");
    enqueue(d,newINTEGER(573));
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
