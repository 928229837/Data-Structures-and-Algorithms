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
    printf("QUEUE tester: 1,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-1-3.c\n");
    printf("\noutput:\n\n");
    QUEUE *d = newQUEUE(displayINTEGER);
    void *p;
    printf("enqueuing items onto queue d\n");
    enqueue(d,newINTEGER(807));
    enqueue(d,newINTEGER(89));
    enqueue(d,newINTEGER(656));
    enqueue(d,newINTEGER(991));
    enqueue(d,newINTEGER(44));
    enqueue(d,newINTEGER(921));
    enqueue(d,newINTEGER(365));
    enqueue(d,newINTEGER(880));
    enqueue(d,newINTEGER(1));
    enqueue(d,newINTEGER(303));
    enqueue(d,newINTEGER(981));
    enqueue(d,newINTEGER(948));
    enqueue(d,newINTEGER(28));
    enqueue(d,newINTEGER(419));
    enqueue(d,newINTEGER(894));
    enqueue(d,newINTEGER(318));
    enqueue(d,newINTEGER(701));
    enqueue(d,newINTEGER(642));
    enqueue(d,newINTEGER(688));
    enqueue(d,newINTEGER(928));
    enqueue(d,newINTEGER(823));
    enqueue(d,newINTEGER(619));
    enqueue(d,newINTEGER(993));
    enqueue(d,newINTEGER(517));
    enqueue(d,newINTEGER(567));
    enqueue(d,newINTEGER(97));
    enqueue(d,newINTEGER(532));
    enqueue(d,newINTEGER(135));
    enqueue(d,newINTEGER(72));
    enqueue(d,newINTEGER(877));
    enqueue(d,newINTEGER(510));
    enqueue(d,newINTEGER(879));
    enqueue(d,newINTEGER(318));
    enqueue(d,newINTEGER(519));
    enqueue(d,newINTEGER(223));
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
    printf("queue d: ");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("dequeuing the last item from queue d\n");
    p = dequeue(d);
    printf("queue d: ");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("enqueuing one item into queue d\n");
    enqueue(d,newINTEGER(715));
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
