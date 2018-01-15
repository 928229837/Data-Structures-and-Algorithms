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
    printf("DA tester: 3,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-3-1.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayREAL);
    insertDA(d,newREAL(8.19));
    insertDA(d,newREAL(5.97));
    insertDA(d,newREAL(0.07));
    insertDA(d,newREAL(8.41));
    insertDA(d,newREAL(2.51));
    insertDA(d,newREAL(3.19));
    insertDA(d,newREAL(3.33));
    visualizeDA(stdout,d);
    printf("\n");
    return 0;
    }
