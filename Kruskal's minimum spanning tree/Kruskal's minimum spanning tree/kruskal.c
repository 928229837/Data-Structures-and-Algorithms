/*
* Kruskal's minimum spanning tree 
* Written by Hansheng Li
*
* Total four step:
* 1. Read Edges
* 2. Sort Edges
* 3. Get MST(Minimum spanning tree) 
* 4. Use BFS(Breadth-first search) print all minimum spanning forest.
*
* 1. Read Edges from file. 
*	e.g. 12 98 75; This line represent as one edge, 
*	whith two vertexs's name 12 and 98, edge weight was 75.
*	If weight is not given (e.g. 12 98;), then weight set as 1.
*	Each edge end with semicolon(;).
*	Use Dynamic array to store edge and vertex.
*	Insert vertexs to Red-black tree.
* -RBT-	   Average	 Worst case
* Space		O(n)	  O(n)
* Search	O(log n)  O(log n)
* Insert	O(log n)  O(log n)
* Delete	O(log n)  O(log n)
*
* 2. Use Merge sort to sort Edges.
*	By compare edge weight or vertex name.
* Average performance:O(n log n)
* Worst-case performance: O(n log n)
* Worst-case space complexity: §°(n)
*
* 3. Get minimum spanning tree by using Disjoint-set to avoid cycle.
*	Creat adjacent Edge and adjacent vertex list to the each vector.
* Average performance: O(|E|log |V|)}
* Worst-case space complexity: ¦¸(|E|+|V|)}
*
* 4. Use BFS to print all minimum spanning forest from given edges.
*	Root will be the smallest number vertex in the tree.
*	Print depth, follow by vertexs and weight, end with total weight.
*	e.g.    $ cat g1
*			1 2 1 ;
*			2 3 2 ;
*			3 1 3 ;
*			$ kruskal g1
*			0: 1
*			1: 2(1)1
*			2: 3(2)2
*			total weight: 3
*			----
* Worst-case performance: O(|V|+|E|)=O(b^d)
* Worst-case space complexity: O(|V|)=O(b^d)
*
* Last update: 2017-11-29
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>

#include "rbt.h"
#include "set.h"
#include "bst.h"
#include "edge.h"
#include "queue.h"
#include "vertex.h"
#include "scanner.h"
#include "integer.h"

int i = 0;
void Fatal(char *, ...);
void BFS(vertex *root, RBT *vertexRBT);
void sortArray(DA *a, int(*cmp)(void *, void *));
void creatMST(DA *mst, DA *edgeList, SET *vertexSet);
void readGraph(FILE *file, SET *vertexSet, DA *edgeList, RBT *vertexRBT);
void mergeSort(DA *a, int lo, int hi, void **aux, int(*cmp)(void *, void *));

int main(int argc, char **argv)
{
	//Check argc is equal to two. 
	if (argc != 2) Fatal("%d arguments!\n", argc - 1);

	//When -v was in the argument line, give author's name and exit
	for (i = 0; i < argc - 1; i++)
	{
		if (!strcmp(argv[i + 1], "-v"))
		{
			printf("Hansheng Li\n");
			exit(0);
		}
	}

	//Open file
	FILE *file;
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Can not open file or it was empty.\n");
		exit(0);
	}
	clock_t begin = clock();
	DA *edgeList = newDA(display_edge);
	SET *vertexSet = newSET(display_vertex);
	RBT *vertexRBT = newRBT(display_vertex, vertex_comparator);
	readGraph(file, vertexSet, edgeList, vertexRBT);
	clock_t end = clock();
	printf("Read graph: %f seconds.\n", ((float)end - begin) / CLOCKS_PER_SEC);

	begin = clock();
	sortArray(edgeList, edge_weight_comparator);
	end = clock();
	printf("Sort array: %f seconds.\n", ((float)end - begin) / CLOCKS_PER_SEC);

	begin = clock();
	DA *mst = newDA(display_edge);
	creatMST(mst, edgeList, vertexSet);
	end = clock();
	printf("Creat MST: %f seconds.\n", ((float)end - begin) / CLOCKS_PER_SEC);

	begin = clock();
	vertex *root;
	while (sizeRBT(vertexRBT))
	{
		root = get_RBT_minimum(vertexRBT);
		BFS(root, vertexRBT);
	}
	end = clock();
	printf("BFS: %f seconds.\n", ((float)end - begin) / CLOCKS_PER_SEC);

	return 0;
}


void Fatal(char *fmt, ...)
{
	va_list ap;
	fprintf(stderr, "An error occured: ");
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	exit(-1);
}

void sortArray(DA *a, int(*cmp)(void *, void *))
{
	void **aux = malloc(sizeof(void *) * sizeDA(a));
	assert(aux != 0);
	mergeSort(a, 0, sizeDA(a), aux, cmp);
	free(aux);
}

void mergeSort(DA *a, int lo, int hi, void **aux, int(*cmp)(void *, void *))
{
	if (lo + 1 >= hi) return;

	int mid = (lo + hi) / 2;

	mergeSort(a, lo, mid, aux, cmp);
	mergeSort(a, mid, hi, aux, cmp);

	int i = lo, j = mid, k = lo;
	while (i < mid && j < hi)
	{
		if (cmp(getDA(a, i), getDA(a, j)) < 0)
			aux[k++] = getDA(a, i++);
		else
			aux[k++] = getDA(a, j++);
	}
	while (i < mid)
		aux[k++] = getDA(a, i++);
	while (j < hi)
		aux[k++] = getDA(a, j++);

	for (i = lo; i < hi; ++i)
		setDA(a, i, aux[i]);
}

void readGraph(FILE *file, SET *vertexSet, DA *edgeList, RBT *vertexRBT)
{
	char *tempS;
	int vertexIndex = 0;
	int tempV = readInt(file);
	while (!feof(file))
	{
		vertex *v1 = newVertex(tempV, vertexIndex);
		vertex *r1 = findRBTvalue(vertexRBT, v1);
		tempV = readInt(file);
		if (v1->name == tempV)
		{
			tempS = readToken(file);
			if (strcmp(tempS, ";"))
				tempS = readToken(file);
			tempV = readInt(file);
			continue;
		}
		if (r1 != NULL)
			v1 = r1;
		else
		{
			vertexIndex++;
			insertRBT(vertexRBT, v1);
			makeSET(vertexSet, v1);
		}

		vertex *v2 = newVertex(tempV, vertexIndex);
		vertex *r2 = findRBTvalue(vertexRBT, v2);

		if (r2 != NULL)
			v2 = r2;
		else
		{
			vertexIndex++;
			insertRBT(vertexRBT, v2);
			makeSET(vertexSet, v2);
		}
		tempS = readToken(file);
		Edge *e;
		if (strcmp(tempS, ";") == 0) {
			e = newEdge(v1, v2, 1);
		}
		else {
			e = newEdge(v1, v2, atoi(tempS));
			tempS = readToken(file);
		}
		insertDA(edgeList, e);
		tempV = readInt(file);
	}
	fclose(file);
}

void creatMST(DA *mst, DA *edgeList, SET *vertexSet)
{
	Edge *tempEdge;
	int index1, index2;
	int numEdge = sizeDA(edgeList);
	for (i = 0; i < numEdge; i++)
	{
		tempEdge = getDA(edgeList, i);
		index1 = tempEdge->first->index;
		index2 = tempEdge->second->index;
		if (findSET(vertexSet, index1) != findSET(vertexSet, index2))
		{
			insertDA(mst, tempEdge);
			insertDA(tempEdge->first->edgeList, tempEdge);
			insertDA(tempEdge->second->edgeList, tempEdge);
			insertDA(tempEdge->first->adjList, tempEdge->second);
			insertDA(tempEdge->second->adjList, tempEdge->first);
			unionSET(vertexSet, index1, index2);
		}
	}
}

void BFS(vertex *root, RBT *vertexRBT)
{
	int j = 0;
	int count = 0;
	int totalWeight = 0;
	Edge *tempEdge = NULL;
	vertex *deqVertex = NULL;
	vertex *tempVertex = NULL;
	DA *tempList = newDA(display_vertex);
	QUEUE *BFS_QUEUE = newQUEUE(display_vertex);
	deleteRBT(vertexRBT, root);
	root->color = 1;
	//Note: color: 0 White 1 gray 2 Black
	enqueue(BFS_QUEUE, NULL);
	enqueue(BFS_QUEUE, root);
	while (sizeQUEUE(BFS_QUEUE))
	{
		deqVertex = dequeue(BFS_QUEUE);
		if (deqVertex == NULL)
		{
			sortArray(tempList, vertex_comparator);
			for (i = 0; i < sizeDA(tempList); i++)
			{
				tempVertex = getDA(tempList, i);
				if (tempVertex->name == root->name) {}
					//printf(" %d", tempVertex->name);
				else
				{
					//printf(" %d(%d)%d", tempVertex->name, tempVertex->pred->name, tempVertex->predWeight);
					deleteRBT(vertexRBT, tempVertex);
					totalWeight += tempVertex->predWeight;
				}
			}
			tempList = newDA(display_vertex);

			if (!sizeQUEUE(BFS_QUEUE))
				break;
			if (count != 0)
			{
				//printf("\n");
				//printf("%d :", count);
			}
			else
				//printf("0 :");
			count++;
			enqueue(BFS_QUEUE, NULL);
		}
		else
		{
			j = 0;
			tempEdge = getDA(deqVertex->edgeList, j);
			for (i = 0; i < sizeDA(deqVertex->adjList); i++)
			{
				tempVertex = getDA(deqVertex->adjList, i);
				if (tempVertex->color == 0)
				{
					tempVertex->color = 1;
					tempVertex->pred = deqVertex;
					tempVertex->predWeight = tempEdge->weight;
					enqueue(BFS_QUEUE, tempVertex);
				}
				j++;
				if (j < sizeDA(deqVertex->edgeList))
					tempEdge = getDA(deqVertex->edgeList, j);
			}
			insertDA(tempList, deqVertex); 
			deqVertex->color = 2;
		}
	}
	//printf("\ntotal weight: %d\n", totalWeight);
	//printf("----\n");
}