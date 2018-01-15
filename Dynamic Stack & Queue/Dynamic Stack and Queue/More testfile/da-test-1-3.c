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
    printf("DA tester: 1,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-1-3.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    void *p = 0;
    printf("inserting items into array d\n");
    insertDA(d,newINTEGER(807));
    insertDA(d,newINTEGER(89));
    insertDA(d,newINTEGER(656));
    insertDA(d,newINTEGER(991));
    insertDA(d,newINTEGER(44));
    insertDA(d,newINTEGER(921));
    insertDA(d,newINTEGER(365));
    insertDA(d,newINTEGER(880));
    insertDA(d,newINTEGER(1));
    insertDA(d,newINTEGER(303));
    insertDA(d,newINTEGER(981));
    insertDA(d,newINTEGER(948));
    insertDA(d,newINTEGER(28));
    insertDA(d,newINTEGER(419));
    insertDA(d,newINTEGER(894));
    insertDA(d,newINTEGER(318));
    insertDA(d,newINTEGER(701));
    insertDA(d,newINTEGER(642));
    insertDA(d,newINTEGER(688));
    insertDA(d,newINTEGER(928));
    insertDA(d,newINTEGER(823));
    insertDA(d,newINTEGER(619));
    insertDA(d,newINTEGER(993));
    insertDA(d,newINTEGER(517));
    insertDA(d,newINTEGER(567));
    insertDA(d,newINTEGER(97));
    insertDA(d,newINTEGER(532));
    insertDA(d,newINTEGER(135));
    insertDA(d,newINTEGER(72));
    insertDA(d,newINTEGER(877));
    insertDA(d,newINTEGER(510));
    insertDA(d,newINTEGER(879));
    insertDA(d,newINTEGER(318));
    insertDA(d,newINTEGER(519));
    insertDA(d,newINTEGER(223));
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
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("removing the last item from array d\n");
    p = removeDA(d);
    printf("array d: ");
    visualizeDA(stdout,d);
    printf("\n");
    printf("inserting one item into array d\n");
    insertDA(d,newINTEGER(715));
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
