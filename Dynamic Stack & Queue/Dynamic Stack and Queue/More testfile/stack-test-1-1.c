#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "integer.h"
#include "real.h"
#include "string.h"
extern long random(void);
extern void srandom(unsigned int seed);

int
main(void)
    {
    printf("STACK tester: 1,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-1-1.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displayREAL);
    push(d,newREAL(8.54));
    push(d,newREAL(6.02));
    push(d,newREAL(1.62));
    push(d,newREAL(4.31));
    push(d,newREAL(2.83));
    push(d,newREAL(5.32));
    printf("trying the visualizer (should call displayDA)\n");
    visualizeSTACK(stdout,d);
    printf("\n");
    return 0;
    }
