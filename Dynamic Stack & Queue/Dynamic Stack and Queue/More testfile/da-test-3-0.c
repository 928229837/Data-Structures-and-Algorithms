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
    printf("DA tester: 3,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-3-0.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(145));
    insertDA(d,newINTEGER(163));
    insertDA(d,newINTEGER(995));
    insertDA(d,newINTEGER(469));
    insertDA(d,newINTEGER(365));
    insertDA(d,newINTEGER(933));
    insertDA(d,newINTEGER(807));
    insertDA(d,newINTEGER(129));
    displayDA(stdout,d);
    printf("\n");
    return 0;
    }
