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
    printf("CDA tester: 2,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-2-3.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAback(d,newINTEGER(856));
    insertCDAback(d,newINTEGER(122));
    insertCDAback(d,newINTEGER(271));
    insertCDAback(d,newINTEGER(538));
    insertCDAback(d,newINTEGER(303));
    insertCDAback(d,newINTEGER(484));
    insertCDAback(d,newINTEGER(939));
    insertCDAback(d,newINTEGER(599));
    visualizeCDA(stdout,d);
    printf("\n");
    return 0;
    }
