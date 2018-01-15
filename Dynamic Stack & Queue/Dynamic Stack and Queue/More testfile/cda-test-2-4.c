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
    printf("CDA tester: 2,4\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-2-4.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    void *p = 0;
    printf("inserting items into array d\n");
    insertCDAback(d,newINTEGER(825));
    insertCDAfront(d,newINTEGER(2));
    insertCDAback(d,newINTEGER(842));
    insertCDAfront(d,newINTEGER(270));
    insertCDAfront(d,newINTEGER(643));
    insertCDAback(d,newINTEGER(657));
    insertCDAfront(d,newINTEGER(379));
    insertCDAfront(d,newINTEGER(879));
    insertCDAfront(d,newINTEGER(576));
    insertCDAfront(d,newINTEGER(210));
    insertCDAfront(d,newINTEGER(320));
    insertCDAfront(d,newINTEGER(737));
    insertCDAfront(d,newINTEGER(909));
    insertCDAback(d,newINTEGER(728));
    insertCDAfront(d,newINTEGER(51));
    insertCDAfront(d,newINTEGER(150));
    insertCDAfront(d,newINTEGER(718));
    insertCDAfront(d,newINTEGER(961));
    insertCDAfront(d,newINTEGER(182));
    insertCDAback(d,newINTEGER(337));
    insertCDAback(d,newINTEGER(888));
    insertCDAfront(d,newINTEGER(384));
    insertCDAback(d,newINTEGER(465));
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
    insertCDAfront(d,newINTEGER(630));
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
