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
    printf("CDA tester: 3,6\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-3-6.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAback(d,newINTEGER(990));
    insertCDAback(d,newINTEGER(453));
    insertCDAback(d,newINTEGER(252));
    insertCDAback(d,newINTEGER(166));
    insertCDAback(d,newINTEGER(61));
    insertCDAback(d,newINTEGER(29));
    insertCDAback(d,newINTEGER(866));
    insertCDAback(d,newINTEGER(430));
    insertCDAback(d,newINTEGER(818));
    insertCDAback(d,newINTEGER(325));
    insertCDAback(d,newINTEGER(254));
    insertCDAback(d,newINTEGER(702));
    insertCDAback(d,newINTEGER(61));
    insertCDAback(d,newINTEGER(419));
    insertCDAback(d,newINTEGER(980));
    insertCDAback(d,newINTEGER(272));
    insertCDAback(d,newINTEGER(558));
    insertCDAback(d,newINTEGER(314));
    insertCDAback(d,newINTEGER(965));
    insertCDAback(d,newINTEGER(671));
    insertCDAback(d,newINTEGER(671));
    insertCDAback(d,newINTEGER(743));
    insertCDAback(d,newINTEGER(286));
    insertCDAback(d,newINTEGER(768));
    insertCDAback(d,newINTEGER(519));
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    void *x = 0;
    x = getCDA(d,sizeCDA(d)-1);
    printf("last element is ");
    displayINTEGER(stdout,x);
    printf("\n");
    void *y = 0;
    y = getCDA(d,0);
    printf("first element is ");
    displayINTEGER(stdout,y);
    printf("\n");
    printf("swapping first and last elements\n");
    x = setCDA(d,0,x);
    y = setCDA(d,sizeCDA(d)-1,y);
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("setting the first available slot\n");
    y = setCDA(d,sizeCDA(d),newINTEGER(433));
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    return 0;
    }
