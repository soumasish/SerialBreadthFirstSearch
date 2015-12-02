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
void bfs(int* vertices, Edge** edges, int num_vertices, int num_edges){

	int level = 0;
	int count = 1;

	while(count < num_vertices){
		for (int i = 0; i < num_vertices; ++i)
		{
			int first = edges[i].first;
			int second = edges[i].second;

			if ((vertices[first] == 0) &&(vertices[second] == -1))
			{
				vertices[second] = level + 1;
				count++;
				
			}else if (vertices[first]!= 0 && (vertices[second] == -1))
			{
				vertices[second] = level + 1;
				count++;
				
			}
			
		}
	}
	

}