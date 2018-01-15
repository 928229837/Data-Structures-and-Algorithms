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
    printf("DA tester: 2,5\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-2-5.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(609));
    insertDA(d,newINTEGER(268));
    insertDA(d,newINTEGER(48));
    insertDA(d,newINTEGER(343));
    insertDA(d,newINTEGER(506));
    insertDA(d,newINTEGER(163));
    insertDA(d,newINTEGER(987));
    insertDA(d,newINTEGER(297));
    insertDA(d,newINTEGER(48));
    insertDA(d,newINTEGER(948));
    insertDA(d,newINTEGER(452));
    insertDA(d,newINTEGER(153));
    insertDA(d,newINTEGER(375));
    insertDA(d,newINTEGER(683));
    insertDA(d,newINTEGER(483));
    insertDA(d,newINTEGER(340));
    insertDA(d,newINTEGER(220));
    insertDA(d,newINTEGER(472));
    insertDA(d,newINTEGER(256));
    insertDA(d,newINTEGER(473));
    insertDA(d,newINTEGER(566));
    insertDA(d,newINTEGER(49));
    insertDA(d,newINTEGER(166));
    insertDA(d,newINTEGER(227));
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
    y = setDA(d,sizeDA(d),newINTEGER(786));
    printf("array d:");
    visualizeDA(stdout,d);
    printf("\n");
    return 0;
    }
