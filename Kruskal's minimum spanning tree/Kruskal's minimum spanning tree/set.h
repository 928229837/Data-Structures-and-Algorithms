/*
* Disjoint Set 
* Written by Hansheng Li
*
* Have Pass Comparison & Union by rank.
* 
* Last update: 2017-11-29
*/
#ifndef __SET_INCLUDED__
#define __SET_INCLUDED__

#include <stdio.h>

typedef struct set SET;

extern SET *newSET(void(*display)(FILE *, void *));
//Pass a display function that can display value in the set. 

extern int countSET(SET *d);
//Give the number of value in the set array.

extern void displaySET(FILE *, SET *d);

extern int findSET(SET *d, int index);
/*Use Pass Comparison. 
* Returns the index of the representative of 
* the value stored at the given index. */

extern int makeSET(SET *d, void *value);
//Store value to that set and return the index that value was stored. 

extern int unionSET(SET *d, int index1, int index2);
/*Use Union by Rank.
* If (they have different Rep(representative))
*	{
*	If (rank a != rank b)
*		Lower #rank Rep->Rep = higher #rank Rep. 
*	else if (rank a == rank b)
*		Higher #index Rep->Rep = lower #index Rep. 
*	Rank ++;
*	return 1;
*	}
* Else 
*	return 0.
*/
#endif