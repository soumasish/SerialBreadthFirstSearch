#include "headers.h"

int main(int argc, char** argv){

	const int NUM_VERTICES = 10000;
	const int NUM_EDGES = 10000;
	const int START_VERTEX = 25;

	clock_t begin, end;
	double time_spent;

	int vertices[NUM_VERTICES];
	Edge* edges[NUM_EDGES];

	initialize_vertices(vertices, NUM_VERTICES, START_VERTEX);

	begin = clock();
	bfs(vertices, edges, NUM_VERTICES, NUM_EDGES);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time taken: %d\n", time_spent);
	
}