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
    printf("DA tester: 1,5\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-1-5.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(383));
    insertDA(d,newINTEGER(918));
    insertDA(d,newINTEGER(795));
    insertDA(d,newINTEGER(466));
    insertDA(d,newINTEGER(577));
    insertDA(d,newINTEGER(636));
    insertDA(d,newINTEGER(182));
    insertDA(d,newINTEGER(988));
    insertDA(d,newINTEGER(52));
    insertDA(d,newINTEGER(471));
    insertDA(d,newINTEGER(194));
    insertDA(d,newINTEGER(731));
    insertDA(d,newINTEGER(26));
    insertDA(d,newINTEGER(841));
    insertDA(d,newINTEGER(938));
    insertDA(d,newINTEGER(472));
    insertDA(d,newINTEGER(542));
    insertDA(d,newINTEGER(27));
    insertDA(d,newINTEGER(232));
    insertDA(d,newINTEGER(694));
    insertDA(d,newINTEGER(271));
    insertDA(d,newINTEGER(959));
    insertDA(d,newINTEGER(170));
    insertDA(d,newINTEGER(342));
    insertDA(d,newINTEGER(524));
    insertDA(d,newINTEGER(326));
    insertDA(d,newINTEGER(35));
    insertDA(d,newINTEGER(310));
    insertDA(d,newINTEGER(553));
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
    y = setDA(d,sizeDA(d),newINTEGER(22));
    printf("array d:");
    visualizeDA(stdout,d);
    printf("\n");
    return 0;
    }
