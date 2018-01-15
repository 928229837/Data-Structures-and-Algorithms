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
    printf("DA tester: 2,6\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-2-6.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(548));
    insertDA(d,newINTEGER(344));
    insertDA(d,newINTEGER(340));
    insertDA(d,newINTEGER(867));
    insertDA(d,newINTEGER(875));
    insertDA(d,newINTEGER(807));
    insertDA(d,newINTEGER(46));
    insertDA(d,newINTEGER(31));
    insertDA(d,newINTEGER(583));
    insertDA(d,newINTEGER(413));
    insertDA(d,newINTEGER(883));
    insertDA(d,newINTEGER(821));
    insertDA(d,newINTEGER(35));
    insertDA(d,newINTEGER(806));
    insertDA(d,newINTEGER(964));
    insertDA(d,newINTEGER(329));
    insertDA(d,newINTEGER(839));
    insertDA(d,newINTEGER(856));
    insertDA(d,newINTEGER(674));
    insertDA(d,newINTEGER(655));
    insertDA(d,newINTEGER(881));
    insertDA(d,newINTEGER(895));
    insertDA(d,newINTEGER(349));
    insertDA(d,newINTEGER(693));
    insertDA(d,newINTEGER(909));
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
