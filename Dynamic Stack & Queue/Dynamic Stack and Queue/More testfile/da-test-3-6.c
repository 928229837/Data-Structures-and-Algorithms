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
    printf("DA tester: 3,6\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-3-6.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(990));
    insertDA(d,newINTEGER(453));
    insertDA(d,newINTEGER(252));
    insertDA(d,newINTEGER(166));
    insertDA(d,newINTEGER(61));
    insertDA(d,newINTEGER(29));
    insertDA(d,newINTEGER(866));
    insertDA(d,newINTEGER(430));
    insertDA(d,newINTEGER(818));
    insertDA(d,newINTEGER(325));
    insertDA(d,newINTEGER(254));
    insertDA(d,newINTEGER(702));
    insertDA(d,newINTEGER(61));
    insertDA(d,newINTEGER(419));
    insertDA(d,newINTEGER(980));
    insertDA(d,newINTEGER(272));
    insertDA(d,newINTEGER(558));
    insertDA(d,newINTEGER(314));
    insertDA(d,newINTEGER(965));
    insertDA(d,newINTEGER(671));
    insertDA(d,newINTEGER(671));
    insertDA(d,newINTEGER(743));
    insertDA(d,newINTEGER(286));
    insertDA(d,newINTEGER(768));
    insertDA(d,newINTEGER(519));
    printf("array d:");
    visualizeDA(stdout,d);
    printf("\n");
    int size = sizeDA(d);
    printf("extracting the underlying array\n");
    void **a = extractDA(d);
    void *p = a[0];
    printf("the first element of the extracted array: ");
    displayINTEGER(stdout,p);
    printf("\n");
    p = a[size-1];
    printf("the last element of the extracted array: ");
    displayINTEGER(stdout,p);
    printf("\n");
    printf("array d:");
    visualizeDA(stdout,d);
    printf("\n");
    return 0;
    }
