/*
* Graph Vertex
* Written by Hansheng Li
*
* Can be used for BFS
* 
* Last update: 2017-11-29
*/
#ifndef VERTEX_H
#define VERTEX_H
#include "da.h"

typedef struct vertex vertex;

struct vertex {
	int name;
	int color;//Use for BFS, White = 0, Gray = 1, Black = 2.
	vertex *pred;//Point to previous vertex, use for FBS.
	int predWeight;//The edge wight between this vertex and previous vertex.
	DA *edgeList;//Store all adjacent Edges to this vertex, use for FBS.
	DA *adjList;//Store all adjacent vertexs to this vertex, use for FBS.
	int index;//Index number in disjoin set, will be used in "find set" function.
};

void display_vertex(FILE *fp, void *value);
extern vertex *newVertex(int name, int index);
extern int vertex_comparator(void *o1, void *o2);
#endif