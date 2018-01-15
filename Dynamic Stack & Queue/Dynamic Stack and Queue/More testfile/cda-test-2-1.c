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
    printf("CDA tester: 2,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-2-1.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayREAL);
    insertCDAback(d,newREAL(0.17));
    insertCDAback(d,newREAL(0.18));
    insertCDAback(d,newREAL(3.05));
    insertCDAback(d,newREAL(5.87));
    insertCDAback(d,newREAL(8.81));
    insertCDAback(d,newREAL(8.65));
    insertCDAback(d,newREAL(8.71));
    displayCDA(stdout,d);
    printf("\n");
    return 0;
    }
