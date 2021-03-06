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
    printf("CDA tester: 3,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-3-3.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAback(d,newINTEGER(939));
    insertCDAback(d,newINTEGER(39));
    insertCDAback(d,newINTEGER(446));
    insertCDAback(d,newINTEGER(942));
    insertCDAback(d,newINTEGER(904));
    insertCDAback(d,newINTEGER(677));
    visualizeCDA(stdout,d);
    printf("\n");
    return 0;
    }
