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
    printf("CDA tester: 3,7\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-3-7.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAfront(d,newINTEGER(545));
    insertCDAfront(d,newINTEGER(66));
    insertCDAfront(d,newINTEGER(190));
    insertCDAfront(d,newINTEGER(876));
    insertCDAfront(d,newINTEGER(595));
    insertCDAfront(d,newINTEGER(786));
    insertCDAfront(d,newINTEGER(423));
    insertCDAfront(d,newINTEGER(565));
    insertCDAfront(d,newINTEGER(361));
    insertCDAfront(d,newINTEGER(312));
    insertCDAfront(d,newINTEGER(887));
    insertCDAfront(d,newINTEGER(954));
    insertCDAfront(d,newINTEGER(670));
    insertCDAfront(d,newINTEGER(371));
    insertCDAfront(d,newINTEGER(570));
    insertCDAfront(d,newINTEGER(896));
    insertCDAfront(d,newINTEGER(295));
    insertCDAfront(d,newINTEGER(160));
    insertCDAfront(d,newINTEGER(192));
    insertCDAfront(d,newINTEGER(404));
    insertCDAfront(d,newINTEGER(340));
    insertCDAfront(d,newINTEGER(187));
    insertCDAfront(d,newINTEGER(247));
    insertCDAfront(d,newINTEGER(711));
    insertCDAfront(d,newINTEGER(402));
    insertCDAfront(d,newINTEGER(746));
    insertCDAfront(d,newINTEGER(976));
    insertCDAfront(d,newINTEGER(957));
    insertCDAfront(d,newINTEGER(901));
    insertCDAfront(d,newINTEGER(64));
    insertCDAfront(d,newINTEGER(645));
    insertCDAfront(d,newINTEGER(798));
    insertCDAfront(d,newINTEGER(131));
    insertCDAfront(d,newINTEGER(836));
    insertCDAfront(d,newINTEGER(675));
    insertCDAfront(d,newINTEGER(78));
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
