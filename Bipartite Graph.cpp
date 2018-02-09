/*
We define graph as a 2D vector. Length(number of rows) of the vector will be number of vertices. In each row, it stores the vertices it connects.
We can use BFS and painting/color solution. We iterate through all vertices, color one as 0, go to its connect vertices to color as 1, then back to 0, and so on. We may need to consider if the graph is not strong connected.

*/


bool isBipartiteGraph(vector<vector<int>> graph){//we can repeatedly call this method to traverse all vertices in case the graph is not strong connected
	vector<int> colors(graph.size(), -1);//every vertices is not colored in the beginning, so we put as -1
	int color = 0;//color is 0 initially, change between 0 and 1 every round
	queue<int> vertices;
	int source = 0;
	vertices.push(source);
	colors[source] = color;
	while(!vertices.empty()){
		color = 1 - color;
		int size = vertices.size();
		while(size){
			int vertex = vertices.front();
			vertices.pop();
			if(colors[vertex] == -1){
				colors[vertex] = color;
				vertices.push(vertex);
			}
			else if(colors[vertex] == 1 - color){
				return false;
			}
			size--;
		}
	}
	return true;
}