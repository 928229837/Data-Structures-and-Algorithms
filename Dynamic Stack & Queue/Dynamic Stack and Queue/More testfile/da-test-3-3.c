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
    printf("DA tester: 3,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-3-3.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    void *p = 0;
    printf("inserting items into array d\n");
    insertDA(d,newINTEGER(939));
    insertDA(d,newINTEGER(39));
    insertDA(d,newINTEGER(446));
    insertDA(d,newINTEGER(942));
    insertDA(d,newINTEGER(904));
    insertDA(d,newINTEGER(677));
    insertDA(d,newINTEGER(350));
    insertDA(d,newINTEGER(55));
    insertDA(d,newINTEGER(631));
    insertDA(d,newINTEGER(36));
    insertDA(d,newINTEGER(232));
    insertDA(d,newINTEGER(848));
    insertDA(d,newINTEGER(236));
    insertDA(d,newINTEGER(984));
    insertDA(d,newINTEGER(827));
    insertDA(d,newINTEGER(101));
    insertDA(d,newINTEGER(924));
    insertDA(d,newINTEGER(995));
    insertDA(d,newINTEGER(399));
    insertDA(d,newINTEGER(822));
    insertDA(d,newINTEGER(962));
    insertDA(d,newINTEGER(60));
    insertDA(d,newINTEGER(852));
    insertDA(d,newINTEGER(300));
    insertDA(d,newINTEGER(573));
    insertDA(d,newINTEGER(545));
    insertDA(d,newINTEGER(173));
    insertDA(d,newINTEGER(618));
    insertDA(d,newINTEGER(329));
    insertDA(d,newINTEGER(451));
    insertDA(d,newINTEGER(94));
    insertDA(d,newINTEGER(269));
    insertDA(d,newINTEGER(842));
    insertDA(d,newINTEGER(892));
    insertDA(d,newINTEGER(563));
    insertDA(d,newINTEGER(746));
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("removing all but one item from array d\n");
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    p = removeDA(d);
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("removing the last item from array d\n");
    p = removeDA(d);
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("inserting one item into array d\n");
    insertDA(d,newINTEGER(922));
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("removing that item\n");
    p = removeDA(d);
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("last element removed: ");
    displayINTEGER(stdout,p);
    printf("\n");
    return 0;
    }
