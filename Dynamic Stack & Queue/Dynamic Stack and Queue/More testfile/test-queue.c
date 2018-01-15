#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "integer.h"
#include "cda.h"
#include "queue.h"


int main(void)
{
	printf("Hello\n\n");

	QUEUE *items = newQUEUE(displayINTEGER);
	int i = 0;


	for (i = 1; i < 10; i++)
	{
		enqueue(items, newINTEGER(i));
	}


	for (i = 1; i < 4; i++)
	{
		dequeue(items);
	}
	dequeue(items);

	printf("\n");
	displayQUEUE(stdout, items);

	printf("\n");
	visualizeQUEUE(stdout, items);

	printf("\n");

	displayINTEGER(stdout, peekQUEUE(items));
	printf("\n");

	printf("%d \n", sizeQUEUE(items));

	return 0;
}


