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
    printf("STACK tester: 2,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-2-1.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displayREAL);
    push(d,newREAL(0.17));
    push(d,newREAL(0.18));
    push(d,newREAL(3.05));
    push(d,newREAL(5.87));
    push(d,newREAL(8.81));
    push(d,newREAL(8.65));
    push(d,newREAL(8.71));
    printf("trying the visualizer (should call displayDA)\n");
    visualizeSTACK(stdout,d);
    printf("\n");
    return 0;
    }
