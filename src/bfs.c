#include "headers.h"

void initialize_vertices(int* vertices, int size, int start_vertex){

	for (int i = 0; i < size; ++i)
	{
		if(i == start_vertex){
			vertices[i] = 0;
		}else{
			vertices[i] = -1;
		}
		
	}

}
int bfs(int* vertices, Edge* edges, int num_vertices, int num_edges){

	int level = 0;
	int modified;

	//continue looping till all vertices have not been updated
	do{
		modified = 0;
		for (int i = 0; i < num_edges; ++i)
		{
			
			int first = edges[i].first;
			int second = edges[i].second;
			

			if ((vertices[first] == level) && (vertices[second] == -1))
			{
				vertices[second] = level + 1;
				modified = 1;
				
			}else if (vertices[second]== level && (vertices[first] == -1))
			{
				vertices[first] = level + 1;
				modified = 1;
				
			}
			
		}//end of for
		level++;
	}while(modified != 0);
	
	return level;
}

// void bfs(int* vertices, Edge** edges, int num_vertices, int num_edges, int starting_vertex){

// }