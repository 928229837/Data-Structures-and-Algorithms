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
    printf("DA tester: 2,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-2-3.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    void *p = 0;
    printf("inserting items into array d\n");
    insertDA(d,newINTEGER(856));
    insertDA(d,newINTEGER(122));
    insertDA(d,newINTEGER(271));
    insertDA(d,newINTEGER(538));
    insertDA(d,newINTEGER(303));
    insertDA(d,newINTEGER(484));
    insertDA(d,newINTEGER(939));
    insertDA(d,newINTEGER(599));
    insertDA(d,newINTEGER(190));
    insertDA(d,newINTEGER(189));
    insertDA(d,newINTEGER(361));
    insertDA(d,newINTEGER(445));
    insertDA(d,newINTEGER(178));
    insertDA(d,newINTEGER(224));
    insertDA(d,newINTEGER(168));
    insertDA(d,newINTEGER(501));
    insertDA(d,newINTEGER(668));
    insertDA(d,newINTEGER(26));
    insertDA(d,newINTEGER(537));
    insertDA(d,newINTEGER(581));
    insertDA(d,newINTEGER(44));
    insertDA(d,newINTEGER(732));
    insertDA(d,newINTEGER(469));
    insertDA(d,newINTEGER(229));
    insertDA(d,newINTEGER(660));
    insertDA(d,newINTEGER(894));
    insertDA(d,newINTEGER(364));
    insertDA(d,newINTEGER(816));
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
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("removing the last item from array d\n");
    p = removeDA(d);
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("inserting one item into array d\n");
    insertDA(d,newINTEGER(573));
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
