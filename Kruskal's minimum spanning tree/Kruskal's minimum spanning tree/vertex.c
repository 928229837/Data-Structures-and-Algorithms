/*
* Graph Vertex
* Written by Hansheng Li
*
* Can be used for BFS(Breadth-first search )
* Function Explanation was in the h file.
*
* Last update: 2017-11-29
*/
#include <stdio.h>
#include <stdlib.h>
#include "vertex.h"
#include "da.h"
#include "edge.h"

int vertex_comparator(void *o1, void *o2)
{
	vertex *a = o1;
	vertex *b = o2;
	return a->name - b->name;
}

vertex *newVertex(int name, int index) {
	vertex *v = malloc(sizeof(vertex));
	v->name = name;
	v->index = index;
	v->adjList = newDA(display_vertex);
	v->color = 0;
	v->pred = NULL;
	v->edgeList = newDA(display_edge);
	v->predWeight = 0;
	return v;
}

void display_vertex(FILE *fp, void *value)
{
	vertex *v = value;
	if (v == NULL)
		fprintf(fp, "NULL");
	else
		fprintf(fp, "%d", v->name);
}