#include<bits/stdc++.h>

using namespace std;

#define INFINITE 100000000

class Graph
{
private:
	int vertices;
	list<pair<int, double> > *adjList;
public:
	Graph(float density, int num);

	void addEdge(int from, int to, double weight);
	double shortestPath(int starting);

	~Graph();
	
};

Graph::Graph(float density, int num)
{
	vertices = num;
	adjList = new list<pair<int, double> >[vertices];

	int totalEdges = vertices * (vertices-1);
	int edgesToAdd = density * totalEdges;
	for (int i = 0; i < edgesToAdd; ++i)
	{
		int from = rand() % vertices;
		int to = rand() % vertices;
		double cost = (double)rand() / RAND_MAX;
		cost = 1.0 + cost * (10.0 - 1.0);

		addEdge(from, to, cost);
	}
}

Graph::~Graph()
{
	delete[] adjList;
}

void Graph::addEdge(int from, int to, double weight)
{
	if (from >= vertices)
	{
		cout << "The input vertex " << from << " is greater than the number of vertices (0-indexed).\n";
		cout << "This will result in invalid memory access. Exiting.";
		exit(0);
	}
	adjList[from].push_back({to, weight});


	if (to >= vertices)
	{
		cout << "The input vertex " << to << " is greater than the number of vertices (0-indexed).\n";
		cout << "This will result in invalid memory access. Exiting.";
		exit(0);
	}
	adjList[to].push_back({from, weight});
}

double Graph::shortestPath(int starting)
{
	//priority queue for storing the vertices that are to be processed.
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pQueue;

	vector<double> distances(vertices, INFINITE);

	pQueue.push({0,starting});
	distances[starting] = 0;	//initial 0 other infinite.

	while(pQueue.empty() == false)
	{
		//first in pqueue is the smallest distance vertex. (bcz of priority queue with greater<>)
		int u = pQueue.top().second;
		pQueue.pop();

		for (auto i = adjList[u].begin(); i != adjList[u].end(); i++)
		{
			int v = (*i).first;
			double weight = (*i).second;

			if (distances[v] > distances[u] + weight)
			{
				distances[v] = distances[u] + weight;
				pQueue.push({distances[v], v});
			}
		}
	}

	double sum = 0.0;
	int count = 0;
	for (int i = 0; i < vertices; ++i)
	{
		cout << "Distance from " << starting << " to the point " << i << " is: ";
		if (abs(distances[i] - INFINITE) <= 0.000001) {
			cout << "NOT FOUND\n";
		}
		else {
			sum += distances[i];
			count++;
			cout << distances[i] << endl;
		}
	}

	return sum/count;
}




int main()
{
	cout << "Nodes: " << 50 << endl;
	double density1 = 0.20;
	cout << "Density: " << density1*100 << endl;
	cout << "-----\n";
	Graph g(0.20, 50);
	double average = g.shortestPath(0);
	cout << "\nThe average is: " << average << endl;


	cout << "\n\n\n";

	cout << "Nodes: " << 50 << endl;
	double density2 = 0.40;
	cout << "Density: " << density2*100 << endl;
	cout << "-----\n";
	Graph g2(0.40, 50);
	double average2 = g2.shortestPath(0);
	cout << "\nThe average is: " << average2 << endl;	

	return 0;
}