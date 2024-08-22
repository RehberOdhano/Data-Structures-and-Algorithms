#include <iostream>
#include <limits.h>
#include "queue.cpp"
// #include "list.cpp"
using namespace std;

class Graph {
	private:
		int** adjacency_matrix;
		int* visited_nodes;
		int* distances;
		int* mst_list;
		int num_of_vertices;
	public:
		// initializing the adjacency matrix to 0
		Graph(int numOfVertices);

		// setting/adding the edge
		void set_edge(int from, int to);

		// removing an edge by the element at [i][j]th position to 0
		void remove_edge(int from, int to);

		// displaying the adjacency matrix
		void display_graph();

		void reset_visited_nodes();

		// Breadth-First Search
		// s -> source node
		void BFS(int s);

		// Depth-First Search
		void DFS(int s);

		void set_distance(int from, int to, int distance);

		// finding the shortest path
		void dijkstra_shortest_path(int src);

		// finding the path with minimum cost
		void prims_MST(int random_node);

		// for finding the valid edge and used in prim's algorithm
		bool is_valid_edge(int u, int v);

		void kruskal_MST(int random_node);

		// destructor - used for removing the adjacency matrix from the memory
		~Graph();
		
};

Graph::Graph(int numOfVertices) {
	this->num_of_vertices = numOfVertices;
	visited_nodes = new int[num_of_vertices];
	mst_list = new int[num_of_vertices];
	distances = new int[num_of_vertices];
	for(int i = 0; i < num_of_vertices; i++) {
		visited_nodes[i] = 0;
		distances[i] = INT_MAX;
		mst_list[i] = 0;
	}

	adjacency_matrix = new int*[num_of_vertices];
	for(int i = 0; i < num_of_vertices; i++) {
		adjacency_matrix[i] = new int[num_of_vertices];
		for(int j = 0; j < num_of_vertices; j++) {
			adjacency_matrix[i][j] = 0;
		}
	}
}

Graph::~Graph() {
	for(int i = 0; i < num_of_vertices; i++) {
		delete[] adjacency_matrix[i];
	}
	delete[] adjacency_matrix;
}

void Graph::display_graph() {
	cout<<"\nGRAPH - ADJACENCY MATRIX"<<endl;
	cout<<"------------------------"<<endl;
	for(int i = 0; i < num_of_vertices; i++) {
		for(int j = 0; j < num_of_vertices; j++) {
			cout<<adjacency_matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"------------------------"<<endl;
}

void Graph::remove_edge(int from, int to) {
	adjacency_matrix[from][to] = 0;
	adjacency_matrix[to][from] = 0;
}

void Graph::set_edge(int from, int to) {
	if((from >= 0 && from < num_of_vertices) && (to >= 0 && to < num_of_vertices)) {
		adjacency_matrix[from][to] = to;
		adjacency_matrix[to][from] = from;
	} else {
		cout<<"PLEASE ENTER A VALID POSITION..."<<endl;
	}
}

void Graph::set_distance(int from, int to, int distance) {
	if((from >= 0 && from < num_of_vertices) && (to >= 0 && to < num_of_vertices)) {
		adjacency_matrix[from][to] = distance;
		adjacency_matrix[to][from] = distance;
	} else {
		cout<<"PLEASE ENTER A VALID POSITION..."<<endl;
	}	
}

void Graph::reset_visited_nodes() {
	for(int i = 0; i < num_of_vertices; i++) {
		visited_nodes[i] = 0;
	}
}

void Graph::BFS(int s) {
	Queue q;
	visited_nodes[s] = 1;
	q.push(s);

	while(!q.isEmpty()) {
		int node = q.pop();
		cout<<node<<" ";

		// neighbours of the current node
		int* nbr = adjacency_matrix[node];

		for(int i = 0; i < num_of_vertices; i++) {
			if(*nbr >= 1 && !visited_nodes[i]) {
				visited_nodes[i] = 1;
				q.push(i);
			}
			nbr++;
		}
	}
}

void Graph::DFS(int s) {
	visited_nodes[s] = 1;
	cout<<s<<" ";

	for(int* it = adjacency_matrix[s]; it != NULL; it++) {
		if(!visited_nodes[*it]) {
			DFS(*it);
		}
	}
}

void Graph::dijkstra_shortest_path(int src) {
	
	Priority_Queue pq;
	pq.push(src);

	// setting the distance of source/starting node to 0
	distances[src] = 0; 

	while(!pq.isEmpty()) {
		int node = pq.pop();
		visited_nodes[node] = 1;
		// neighbours of the current node "node"
		int* nbrs = adjacency_matrix[node];

		for(int i = 0; i < num_of_vertices; i++) {
			// check if there is an edge or not and if the node is already
			// visited or not
			if(nbrs[i] > 0 && !visited_nodes[i]) {
				if(distances[node] + nbrs[i] < distances[i]) {
					distances[i] = distances[node] + nbrs[i];
					pq.push(i);
					// nbrs++;
				}
			} 
		}
	}

	for(int i = 0; i < num_of_vertices; i++) {
		if(distances[i] == INT_MAX) cout<<" -1 ";
		else cout<<distances[i]<<" "; 
	}
}

bool Graph::is_valid_edge(int u, int v) {
	// checks whether the edge(i, j) is valid or not
	// A valid egde is one whose one end is already 
	// included in mst_list and other end is not in mst_list
	if(u == v) return false;
	if(mst_list[u] == 0 && mst_list[v] == 0) return false;
	if(mst_list[u] == 1 && mst_list[v] == 1) return false;

	return true;
}

void Graph::prims_MST(int random_node) {
	// Priority_Queue pq;
	// pq.push(random_node);

	mst_list[random_node] = 1;
	int num_of_edges = 0, min_cost_of_path = 0;
	while(num_of_edges < (num_of_vertices - 1)) {

		// finding the valid edge with minimum cost
		int min = INT_MAX, p = -1, q = -1;
		for(int i = 0; i < num_of_vertices; i++) {
			for(int j = 0; j < num_of_vertices; j++) {
				if(is_valid_edge(i, j)) {
					min = adjacency_matrix[i][j];
					p = i;
					q = j;
				}
			}
		}
		if(p != -1 && q != -1) {
			min_cost_of_path += min;
			mst_list[q] = mst_list[p] = 1;
			num_of_edges++;
		}
	}
	cout<<"\nMinimum Cost: "<<min_cost_of_path<<endl;
}

int main() {
	// Graph graph(4);
	// graph.set_edge(0, 1);
 //    graph.set_edge(0, 2);
 //    graph.set_edge(1, 2);
 //    graph.set_edge(2, 0);
 //    graph.set_edge(2, 3);
 //    graph.set_edge(3, 3);

	// Graph graph(4);
	// graph.set_distance(0, 1, 5);
 //    graph.set_distance(0, 2, 6);
 //    graph.set_distance(1, 2, 1);
 //    graph.set_distance(2, 3, 4);
 //    graph.set_distance(3, 1, 10);

	Graph graph(4);
	graph.set_distance(0,1,1);
	graph.set_distance(0,3,4);
	graph.set_distance(0,2,3);
	graph.set_distance(1,2,2);
	graph.set_distance(2,3,5);

	graph.display_graph();

	// graph.BFS(0);
	// cout<<endl;

	// graph.reset_visited_nodes();
	// graph.DFS(0);

	// graph.dijkstra_shortest_path(0);
	graph.prims_MST(0);


	return 0;
}