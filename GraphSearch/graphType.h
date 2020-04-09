// C++ program to print DFS traversal from 
// a given vertex in a given graph 
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct graphEdge
{
	int start_ver;
	int end_ver;
};

// Graph class represents a directed graph 
// using adjacency list representation 
class Graph
{
	int V; // No. of vertices 

	// Pointer to an array containing 
	// adjacency lists 
	vector<int>* adj;

	// A recursive function used by DFS 
	void DFSUtil(int v, bool visited[]);

	// A function used by topologicalSort 
	void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);

public:
	Graph(int V, vector<graphEdge> edges); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w);

	// DFS traversal of the vertices 
	// reachable from v 
	// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
	void DFS(int v);

	// Breath first search
	// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/?ref=rp
	void BFS(int s);

	// prints a Topological Sort of the complete graph 
	// https://www.geeksforgeeks.org/topological-sorting/
	void topologicalSort();
};

Graph::Graph(int V, vector<graphEdge> edges)
{
	this->V = V;
	adj = new vector<int>[V];
	
	vector<graphEdge>::iterator i;
	for (i = edges.begin(); i != edges.end(); ++i)
		addEdge((*i).start_ver, (*i).end_ver);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list. 
}

void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and 
	// print it 
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent 
	// to this vertex 
	vector<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v)
{
	// Mark all the vertices as not visited 
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function 
	// to print DFS traversal 
	DFSUtil(v, visited);
}


void Graph::BFS(int s)
{
	// Mark all the vertices as not visited 
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS 
	vector<int> queue;

	// Mark the current node as visited and enqueue it 
	visited[s] = true;
	queue.push_back(s);

	// 'i' will be used to get all adjacent 
	// vertices of a vertex 
	vector<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it 
		s = queue.front();
		cout << s << " ";
		queue.erase(queue.begin()); // Pop front

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited,  
		// then mark it visited and enqueue it 
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(int v, bool visited[],
	stack<int>& Stack)
{
	// Mark the current node as visited. 
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex 
	vector<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);

	// Push current vertex to stack which stores result 
	Stack.push(v);
}

// The function to do Topological Sort. It uses recursive  
// topologicalSortUtil() 
void Graph::topologicalSort()
{
	stack<int> Stack;

	// Mark all the vertices as not visited 
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to store Topological 
	// Sort starting from all vertices one by one 
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	// Print contents of stack 
	while (Stack.empty() == false)
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
}