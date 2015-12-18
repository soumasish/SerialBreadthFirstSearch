#include "headers.h"

int main(int argc, char** argv){

	const int NUM_VERTICES = 1024;
	const int NUM_EDGES = 2048;
	const int START_VERTEX = 147;


	clock_t begin, end;
	double time_spent;

	int vertices[NUM_VERTICES];
	Edge edges[NUM_EDGES];
	int first, second;

	FILE *infile;
    char *path = "DataSet/1024-2048.txt";
    char line[100];

    infile = fopen(path, "r");

  	if (!infile) {
    	printf("Couldn't open %s for reading\n", path);
    	exit(-1);
  	}
  	int i=0;
	while (fgets(line, sizeof(line), infile)!= NULL) 
	{
		
		sscanf(line, "%d\t%d", &first, &second);

	    edges[i].first = first;
	    edges[i].second = second;
	    i++;
	}
	
	fclose(infile);
	// printf("Data Set:\n\n");


	// for (int i = 0; i < NUM_EDGES; ++i)
	// {
	// 	printf("%d -> %d", edges[i].first, edges[i].second);
	// 	printf(((i % 4) != 3) ? "\t":"\n");
	// }

	//printf("Initialized vertices\n\n");
	initialize_vertices(vertices, NUM_VERTICES, START_VERTEX);

	// for (int i = 0; i < NUM_VERTICES; ++i)
	// {
	// 	printf("%d : %d", i, vertices[i]);
	// 	printf(((i % 4) != 3) ? "\t":"\n");
	// }

	begin = clock();
	int final_level = bfs(vertices, edges, NUM_VERTICES, NUM_EDGES);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	for (int i = 0; i < NUM_VERTICES; ++i)
	{
		printf("%d : %d", i, vertices[i]);
		printf(((i % 4) != 3) ? "\t":"\n");
	}
	printf("BFS completed over %d levels\n", final_level);
	printf("Time taken: %f\n", time_spent);

	

	return 0;
	
}