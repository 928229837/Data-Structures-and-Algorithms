#include <stdio.h>
#include <stdlib.h>
#include "da.h"
#include "integer.h"
#include "real.h"
#include "string.h"
extern long random(void);
extern void srandom(unsigned int seed);

int
main(void)
    {
    printf("DA tester: 2,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-2-1.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayREAL);
    insertDA(d,newREAL(0.17));
    insertDA(d,newREAL(0.18));
    insertDA(d,newREAL(3.05));
    insertDA(d,newREAL(5.87));
    insertDA(d,newREAL(8.81));
    insertDA(d,newREAL(8.65));
    insertDA(d,newREAL(8.71));
    visualizeDA(stdout,d);
    printf("\n");
    return 0;
    }
