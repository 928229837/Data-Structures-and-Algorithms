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
    printf("CDA tester: 1,6\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-1-6.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAback(d,newINTEGER(189));
    insertCDAback(d,newINTEGER(468));
    insertCDAback(d,newINTEGER(583));
    insertCDAback(d,newINTEGER(868));
    insertCDAback(d,newINTEGER(885));
    insertCDAback(d,newINTEGER(35));
    insertCDAback(d,newINTEGER(592));
    insertCDAback(d,newINTEGER(686));
    insertCDAback(d,newINTEGER(32));
    insertCDAback(d,newINTEGER(874));
    insertCDAback(d,newINTEGER(222));
    insertCDAback(d,newINTEGER(631));
    insertCDAback(d,newINTEGER(281));
    insertCDAback(d,newINTEGER(719));
    insertCDAback(d,newINTEGER(909));
    insertCDAback(d,newINTEGER(828));
    insertCDAback(d,newINTEGER(395));
    insertCDAback(d,newINTEGER(481));
    insertCDAback(d,newINTEGER(674));
    insertCDAback(d,newINTEGER(442));
    insertCDAback(d,newINTEGER(346));
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
    y = setCDA(d,sizeCDA(d),newINTEGER(299));
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    return 0;
    }
