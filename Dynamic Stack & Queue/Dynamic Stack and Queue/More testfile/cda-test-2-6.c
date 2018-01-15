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
    printf("CDA tester: 2,6\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-2-6.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAback(d,newINTEGER(548));
    insertCDAback(d,newINTEGER(344));
    insertCDAback(d,newINTEGER(340));
    insertCDAback(d,newINTEGER(867));
    insertCDAback(d,newINTEGER(875));
    insertCDAback(d,newINTEGER(807));
    insertCDAback(d,newINTEGER(46));
    insertCDAback(d,newINTEGER(31));
    insertCDAback(d,newINTEGER(583));
    insertCDAback(d,newINTEGER(413));
    insertCDAback(d,newINTEGER(883));
    insertCDAback(d,newINTEGER(821));
    insertCDAback(d,newINTEGER(35));
    insertCDAback(d,newINTEGER(806));
    insertCDAback(d,newINTEGER(964));
    insertCDAback(d,newINTEGER(329));
    insertCDAback(d,newINTEGER(839));
    insertCDAback(d,newINTEGER(856));
    insertCDAback(d,newINTEGER(674));
    insertCDAback(d,newINTEGER(655));
    insertCDAback(d,newINTEGER(881));
    insertCDAback(d,newINTEGER(895));
    insertCDAback(d,newINTEGER(349));
    insertCDAback(d,newINTEGER(693));
    insertCDAback(d,newINTEGER(909));
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
    y = setCDA(d,sizeCDA(d),newINTEGER(802));
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    return 0;
    }
