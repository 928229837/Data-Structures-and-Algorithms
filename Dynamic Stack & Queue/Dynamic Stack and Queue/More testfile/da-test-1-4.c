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
    printf("DA tester: 1,4\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-1-4.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(607));
    insertDA(d,newINTEGER(102));
    insertDA(d,newINTEGER(40));
    insertDA(d,newINTEGER(468));
    insertDA(d,newINTEGER(123));
    insertDA(d,newINTEGER(448));
    insertDA(d,newINTEGER(152));
    insertDA(d,newINTEGER(595));
    insertDA(d,newINTEGER(637));
    insertDA(d,newINTEGER(466));
    insertDA(d,newINTEGER(46));
    insertDA(d,newINTEGER(949));
    insertDA(d,newINTEGER(484));
    insertDA(d,newINTEGER(465));
    insertDA(d,newINTEGER(282));
    insertDA(d,newINTEGER(106));
    insertDA(d,newINTEGER(840));
    insertDA(d,newINTEGER(109));
    insertDA(d,newINTEGER(375));
    insertDA(d,newINTEGER(341));
    insertDA(d,newINTEGER(473));
    insertDA(d,newINTEGER(131));
    insertDA(d,newINTEGER(188));
    printf("array d:");
    visualizeDA(stdout,d);
    printf("\n");
    DA *e = newDA(displayINTEGER);
    insertDA(e,newINTEGER(217));
    insertDA(e,newINTEGER(882));
    insertDA(e,newINTEGER(787));
    insertDA(e,newINTEGER(736));
    insertDA(e,newINTEGER(685));
    insertDA(e,newINTEGER(321));
    insertDA(e,newINTEGER(98));
    insertDA(e,newINTEGER(860));
    insertDA(e,newINTEGER(928));
    insertDA(e,newINTEGER(200));
    insertDA(e,newINTEGER(900));
    insertDA(e,newINTEGER(749));
    insertDA(e,newINTEGER(323));
    insertDA(e,newINTEGER(700));
    insertDA(e,newINTEGER(901));
    insertDA(e,newINTEGER(918));
    insertDA(e,newINTEGER(338));
    insertDA(e,newINTEGER(719));
    insertDA(e,newINTEGER(316));
    insertDA(e,newINTEGER(639));
    insertDA(e,newINTEGER(555));
    insertDA(e,newINTEGER(133));
    insertDA(e,newINTEGER(922));
    insertDA(e,newINTEGER(661));
    insertDA(e,newINTEGER(974));
    insertDA(e,newINTEGER(383));
    insertDA(e,newINTEGER(389));
    insertDA(e,newINTEGER(315));
    insertDA(e,newINTEGER(857));
    insertDA(e,newINTEGER(520));
    insertDA(e,newINTEGER(855));
    insertDA(e,newINTEGER(426));
    insertDA(e,newINTEGER(403));
    insertDA(e,newINTEGER(994));
    insertDA(e,newINTEGER(162));
    insertDA(e,newINTEGER(440));
    insertDA(e,newINTEGER(315));
    insertDA(e,newINTEGER(612));
    insertDA(e,newINTEGER(300));
    insertDA(e,newINTEGER(596));
    insertDA(e,newINTEGER(812));
    insertDA(e,newINTEGER(552));
    insertDA(e,newINTEGER(345));
    insertDA(e,newINTEGER(135));
    insertDA(e,newINTEGER(252));
    insertDA(e,newINTEGER(598));
    printf("array e:");
    visualizeDA(stdout,e);
    printf("\n");
    printf("performing unionDA(d,e)\n");
    unionDA(d,e);
    printf("\n");
    printf("array d: ");
    displayDA(stdout,d);
    printf("\n");
    printf("array e: ");
    displayDA(stdout,e);
    printf("\n");
    printf("performing unionDA(d,e)\n");
    unionDA(d,e);
    printf("\n");
    printf("array d: ");
    displayDA(stdout,d);
    printf("\n");
    printf("array e: ");
    displayDA(stdout,e);
    printf("\n");
    printf("performing unionDA(e,d)\n");
    unionDA(e,d);
    printf("\n");
    printf("array d: ");
    displayDA(stdout,d);
    printf("\n");
    printf("array e: ");
    displayDA(stdout,e);
    printf("\n");
    return 0;
    }
