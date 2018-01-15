/*
* Graph Edge
* Written by Hansheng Li
*
* Last update: 2017-11-29
*/
#ifndef EDGE_H
#define EDGE_H

#include "da.h"
#include "vertex.h"

typedef struct Edge Edge;

struct Edge {
	vertex *first;
	vertex *second;
	int weight;
};

extern Edge *newEdge(vertex *, vertex *, int);

extern void display_edge(FILE *fp, void *value);
extern int edge_weight_comparator(void *o1, void *o2);
/*Compare edge weight.
* If (wight was same)
*	Compare smaller vertex in each edge.
*	If (Still same)
*		Compare bigger vertex in each edge.
*/
#endif