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
    printf("DA tester: 3,5\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-3-5.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(404));
    insertDA(d,newINTEGER(381));
    insertDA(d,newINTEGER(759));
    insertDA(d,newINTEGER(181));
    insertDA(d,newINTEGER(729));
    insertDA(d,newINTEGER(603));
    insertDA(d,newINTEGER(304));
    insertDA(d,newINTEGER(23));
    insertDA(d,newINTEGER(707));
    insertDA(d,newINTEGER(606));
    insertDA(d,newINTEGER(409));
    insertDA(d,newINTEGER(230));
    insertDA(d,newINTEGER(347));
    insertDA(d,newINTEGER(361));
    insertDA(d,newINTEGER(121));
    insertDA(d,newINTEGER(34));
    insertDA(d,newINTEGER(587));
    insertDA(d,newINTEGER(405));
    insertDA(d,newINTEGER(24));
    insertDA(d,newINTEGER(915));
    insertDA(d,newINTEGER(386));
    insertDA(d,newINTEGER(400));
    insertDA(d,newINTEGER(68));
    insertDA(d,newINTEGER(530));
    insertDA(d,newINTEGER(983));
    insertDA(d,newINTEGER(169));
    insertDA(d,newINTEGER(970));
    insertDA(d,newINTEGER(751));
    insertDA(d,newINTEGER(932));
    insertDA(d,newINTEGER(378));
    insertDA(d,newINTEGER(768));
    insertDA(d,newINTEGER(688));
    insertDA(d,newINTEGER(759));
    insertDA(d,newINTEGER(879));
    insertDA(d,newINTEGER(221));
    insertDA(d,newINTEGER(840));
    printf("array d:");
    visualizeDA(stdout,d);
    printf("\n");
    void *x = 0;
    x = getDA(d,sizeDA(d)-1);
    printf("last element is ");
    displayINTEGER(stdout,x);
    printf("\n");
    void *y = 0;
    y = getDA(d,0);
    printf("first element is ");
    displayINTEGER(stdout,y);
    printf("\n");
    printf("swapping first and last elements\n");
    x = setDA(d,0,x);
    y = setDA(d,sizeDA(d)-1,y);
    printf("array d:");
    visualizeDA(stdout,d);
    printf("\n");
    printf("setting the first available slot\n");
    y = setDA(d,sizeDA(d),newINTEGER(834));
    printf("array d:");
    visualizeDA(stdout,d);
    printf("\n");
    return 0;
    }
