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
    printf("QUEUE tester: 3,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-3-1.c\n");
    printf("\noutput:\n\n");
    QUEUE *d = newQUEUE(displayREAL);
    enqueue(d,newREAL(8.19));
    enqueue(d,newREAL(5.97));
    enqueue(d,newREAL(0.07));
    enqueue(d,newREAL(8.41));
    enqueue(d,newREAL(2.51));
    enqueue(d,newREAL(3.19));
    enqueue(d,newREAL(3.33));
    printf("trying the visualizer (should call displayCDA)\n");
    visualizeQUEUE(stdout,d);
    printf("\n");
    return 0;
    }
