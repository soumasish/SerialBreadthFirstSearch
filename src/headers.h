#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Edge{
	int first;
	int second;
}Edge;

int bfs(int* vertices, Edge* edges, int num_vertices, int num_edges);
void initialize_vertices(int* vertices, int size, int start_vertex);