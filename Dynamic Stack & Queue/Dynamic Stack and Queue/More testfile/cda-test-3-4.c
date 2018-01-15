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
    printf("CDA tester: 3,4\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-3-4.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    void *p = 0;
    printf("inserting items into array d\n");
    insertCDAback(d,newINTEGER(758));
    insertCDAfront(d,newINTEGER(177));
    insertCDAfront(d,newINTEGER(68));
    insertCDAfront(d,newINTEGER(680));
    insertCDAfront(d,newINTEGER(870));
    insertCDAfront(d,newINTEGER(526));
    insertCDAfront(d,newINTEGER(92));
    insertCDAback(d,newINTEGER(694));
    insertCDAfront(d,newINTEGER(923));
    insertCDAback(d,newINTEGER(682));
    insertCDAfront(d,newINTEGER(226));
    insertCDAback(d,newINTEGER(573));
    insertCDAfront(d,newINTEGER(270));
    insertCDAback(d,newINTEGER(25));
    insertCDAback(d,newINTEGER(3));
    insertCDAback(d,newINTEGER(601));
    insertCDAback(d,newINTEGER(213));
    insertCDAfront(d,newINTEGER(308));
    insertCDAfront(d,newINTEGER(794));
    insertCDAfront(d,newINTEGER(162));
    insertCDAfront(d,newINTEGER(440));
    insertCDAfront(d,newINTEGER(653));
    insertCDAback(d,newINTEGER(440));
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("removing all but one item from array d\n");
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("removing the last item from array d\n");
    p = removeCDAback(d);
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("inserting one item into array d\n");
    insertCDAfront(d,newINTEGER(558));
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("removing that item\n");
    p = removeCDAback(d);
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("looking at the last element removed\n");
    printf("last element removed: ");
    displayINTEGER(stdout,p);
    printf("\n");
    return 0;
    }
