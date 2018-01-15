/*
* Graph Edge 
* Written by Hansheng Li
*
* Function Explanation was in the h file.
*
* Last update: 2017-11-29
*/
#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "vertex.h"

vertex *get_minimum_vertex(Edge *e);
vertex *get_maximum_vertex(Edge *e);

Edge *newEdge(vertex *v1, vertex *v2, int weight) {
	Edge *e = malloc(sizeof(Edge));
	e->first = v1;
	e->second = v2;
	e->weight = weight;
	return e;
}

int edge_weight_comparator(void *o1, void *o2) {
	Edge *a = o1;
	Edge *b = o2;
	int result = a->weight - b->weight;
	if (result != 0)
		return result;
	result = vertex_comparator(get_minimum_vertex(a), get_minimum_vertex(b));
	if (result != 0)
		return result;
	result = vertex_comparator(get_maximum_vertex(a), get_maximum_vertex(b));
	return result;
}

vertex *get_minimum_vertex(Edge *e)
{
	if (vertex_comparator(e->first, e->second) < 0)
		return e->first;
	return e->second;
}

vertex *get_maximum_vertex(Edge *e)
{
	if (vertex_comparator(e->first, e->second) < 0)
		return e->second;
	return e->first;
}

void display_edge(FILE *fp, void * value)
{
	Edge *e = value;
	fprintf(fp, "** %d %d %d **\n", e->first->name, e->second->name, e->weight);
}

