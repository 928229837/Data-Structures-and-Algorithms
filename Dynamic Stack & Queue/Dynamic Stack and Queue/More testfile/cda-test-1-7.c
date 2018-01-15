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
    printf("CDA tester: 1,7\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-1-7.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAfront(d,newINTEGER(443));
    insertCDAfront(d,newINTEGER(262));
    insertCDAfront(d,newINTEGER(449));
    insertCDAfront(d,newINTEGER(79));
    insertCDAfront(d,newINTEGER(922));
    insertCDAfront(d,newINTEGER(785));
    insertCDAfront(d,newINTEGER(777));
    insertCDAfront(d,newINTEGER(864));
    insertCDAfront(d,newINTEGER(52));
    insertCDAfront(d,newINTEGER(621));
    insertCDAfront(d,newINTEGER(44));
    insertCDAfront(d,newINTEGER(921));
    insertCDAfront(d,newINTEGER(694));
    insertCDAfront(d,newINTEGER(342));
    insertCDAfront(d,newINTEGER(503));
    insertCDAfront(d,newINTEGER(151));
    insertCDAfront(d,newINTEGER(292));
    insertCDAfront(d,newINTEGER(132));
    insertCDAfront(d,newINTEGER(106));
    insertCDAfront(d,newINTEGER(332));
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    int size = sizeCDA(d);
    printf("extracting the underlying array\n");
    void **a = extractCDA(d);
    void *p = a[0];
    printf("the first element of the extracted array: ");
    displayINTEGER(stdout,p);
    printf("\n");
    p = a[size-1];
    printf("the last element of the extracted array: ");
    displayINTEGER(stdout,p);
    printf("\n");
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    return 0;
    }
