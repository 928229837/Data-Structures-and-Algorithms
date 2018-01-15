#include <stdio.h>
#include <stdlib.h>
#include "cda.h"
#include "integer.h"
#include "real.h"
#include "string.h"
extern long random(void);
extern void srandom(unsigned int seed);

int
main(void)
    {
    printf("CDA tester: 1,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-1-1.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayREAL);
    insertCDAback(d,newREAL(8.54));
    insertCDAback(d,newREAL(6.02));
    insertCDAback(d,newREAL(1.62));
    insertCDAback(d,newREAL(4.31));
    insertCDAback(d,newREAL(2.83));
    insertCDAback(d,newREAL(5.32));
    displayCDA(stdout,d);
    printf("\n");
    return 0;
    }
