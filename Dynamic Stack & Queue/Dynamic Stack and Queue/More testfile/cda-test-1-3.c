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
    printf("CDA tester: 1,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-1-3.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAback(d,newINTEGER(807));
    insertCDAback(d,newINTEGER(89));
    insertCDAback(d,newINTEGER(656));
    insertCDAback(d,newINTEGER(991));
    insertCDAback(d,newINTEGER(44));
    visualizeCDA(stdout,d);
    printf("\n");
    return 0;
    }
