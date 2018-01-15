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
    printf("CDA tester: 2,7\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-2-7.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAfront(d,newINTEGER(681));
    insertCDAfront(d,newINTEGER(88));
    insertCDAfront(d,newINTEGER(408));
    insertCDAfront(d,newINTEGER(42));
    insertCDAfront(d,newINTEGER(737));
    insertCDAfront(d,newINTEGER(500));
    insertCDAfront(d,newINTEGER(975));
    insertCDAfront(d,newINTEGER(153));
    insertCDAfront(d,newINTEGER(248));
    insertCDAfront(d,newINTEGER(498));
    insertCDAfront(d,newINTEGER(764));
    insertCDAfront(d,newINTEGER(57));
    insertCDAfront(d,newINTEGER(991));
    insertCDAfront(d,newINTEGER(791));
    insertCDAfront(d,newINTEGER(161));
    insertCDAfront(d,newINTEGER(210));
    insertCDAfront(d,newINTEGER(596));
    insertCDAfront(d,newINTEGER(591));
    insertCDAfront(d,newINTEGER(204));
    insertCDAfront(d,newINTEGER(954));
    insertCDAfront(d,newINTEGER(812));
    insertCDAfront(d,newINTEGER(131));
    insertCDAfront(d,newINTEGER(154));
    insertCDAfront(d,newINTEGER(96));
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
