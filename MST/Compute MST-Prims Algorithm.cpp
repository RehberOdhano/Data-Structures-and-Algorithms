#include<bits/stdc++.h>

using namespace std;

#define INFINITE 100000000

class Graph
{
private:
	int vertices;
	list<pair<int, double> > *adjList;

	double** adjMatrix;
public:
	Graph(float density, int num);
	Graph(string filename);

	void addEdge(int from, int to, double weight);
	double shortestPath(int starting);

	void primMST();

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

Graph::Graph(string filename)
{
	ifstream infile(filename);

	int n;
	infile >> n;

	vertices = n;
	adjList = new list<pair<int, double> >[vertices];

	adjMatrix = new double*[vertices];
	for (int i = 0; i < vertices; ++i)
	{
		adjMatrix[i] = new double[vertices];
	}

	for (int i = 0; i < vertices; ++i)
	{
		for (int j = 0; j < vertices; j++)
			adjMatrix[i][j] = -1;
	}

	int from, to;
	double cost;
	while (infile >> from >> to >> cost)
	{
		addEdge(from, to, cost);
		adjMatrix[from][to] = cost;
		adjMatrix[to][from] = cost;
	}

	infile.close();
}

void Graph::primMST() 
{ 
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > queue;

	vector<int> key(vertices, INFINITE);
	vector<int> parent(vertices, -1);
	vector<bool> inMST(vertices, false);

	queue.push(make_pair(0, 0));
	key[0] = 0;

	while (!queue.empty())
	{
		int u = queue.top().second;
		queue.pop();

		inMST[u] = true;
		// vector<pair<int, double> >::iterator it;
		for (auto it = adjList[u].begin(); it != adjList[u].end(); it++)
		{
			int v = (*it).first;
			int weight = (*it).second;

			if (!inMST[v] && key[v] > weight)
			{
				key[v] = weight;
				queue.push(make_pair(key[v], v));
				parent[v] = u;
			}
		}

	}

	long long mincost = 0;
	cout << "Node\tNode\tCost\n";
	for (int i = 1; i < vertices; i++)
	{
		int cost = adjMatrix[parent[i]][i];
		cout << parent[i] << "\t" << i << "\t" << cost << endl;
		mincost += cost;
	}
	cout << "Total minimum cost: " << mincost << endl;

	for (int i = 0; i < vertices; ++i)
	{
		delete[] adjMatrix[i];
	}
	delete[] adjMatrix;
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
	Graph g("input.txt");

	g.primMST();

	return 0;
}