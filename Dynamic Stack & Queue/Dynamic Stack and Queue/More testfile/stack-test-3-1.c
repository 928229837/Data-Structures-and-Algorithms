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
    printf("STACK tester: 3,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-3-1.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displayREAL);
    push(d,newREAL(8.19));
    push(d,newREAL(5.97));
    push(d,newREAL(0.07));
    push(d,newREAL(8.41));
    push(d,newREAL(2.51));
    push(d,newREAL(3.19));
    push(d,newREAL(3.33));
    printf("trying the visualizer (should call displayDA)\n");
    visualizeSTACK(stdout,d);
    printf("\n");
    return 0;
    }
