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
    printf("DA tester: 1,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-1-1.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayREAL);
    insertDA(d,newREAL(8.54));
    insertDA(d,newREAL(6.02));
    insertDA(d,newREAL(1.62));
    insertDA(d,newREAL(4.31));
    insertDA(d,newREAL(2.83));
    insertDA(d,newREAL(5.32));
    visualizeDA(stdout,d);
    printf("\n");
    return 0;
    }
