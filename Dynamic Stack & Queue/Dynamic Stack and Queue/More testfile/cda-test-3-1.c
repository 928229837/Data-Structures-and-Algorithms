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
    printf("CDA tester: 3,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-3-1.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayREAL);
    insertCDAback(d,newREAL(8.19));
    insertCDAback(d,newREAL(5.97));
    insertCDAback(d,newREAL(0.07));
    insertCDAback(d,newREAL(8.41));
    insertCDAback(d,newREAL(2.51));
    insertCDAback(d,newREAL(3.19));
    insertCDAback(d,newREAL(3.33));
    displayCDA(stdout,d);
    printf("\n");
    return 0;
    }
