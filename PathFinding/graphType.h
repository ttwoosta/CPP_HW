// C++ program to print DFS traversal from 
// a given vertex in a given graph 
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

# define INF 0x3f3f3f3f 

struct graphEdge
{
	int start_ver;
	int end_ver;
	int cost;
	int from_node_x;
	int from_node_y;
	int to_node_x;
	int to_node_y;
};

// Graph class represents a directed graph 
// using adjacency list representation 
class Graph
{
	int V; // No. of vertices 

	// A recursive function used by DFS 
	void DFSUtil(int v, bool visited[]);

public:

	// Pointer to an array containing 
	// adjacency lists 
	vector<graphEdge>* adj;

	Graph(int V, vector<graphEdge> edges); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, graphEdge e);

	void printGraph();

	// DFS traversal of the vertices 
	// reachable from v 
	// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
	void DFS(int v);

	// 
	// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/?ref=rp
	void shortestPath(int src);
};

Graph::Graph(int V, vector<graphEdge> edges)
{
	this->V = V;
	adj = new vector<graphEdge>[V];
	
	vector<graphEdge>::iterator i;
	for (i = edges.begin(); i != edges.end(); ++i)
		addEdge((*i).start_ver, (*i));
}

void Graph::addEdge(int v, graphEdge e)
{
	adj[v].push_back(e); // Add w to v’s list. 
}

void Graph::printGraph() {
	for (int v = 0; v < V; v++)
	{
		vector<graphEdge>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
			printf("(%d, %d, %d, %d, %d, %d, %d)\n", (*i).start_ver,
				(*i).end_ver, (*i).cost, (*i).from_node_x, (*i).from_node_y,
				(*i).to_node_x, (*i).to_node_y);
	}
}

void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and 
	// print it 
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent 
	// to this vertex 
	vector<graphEdge>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[(*i).end_ver])
			DFSUtil((*i).end_ver, visited);
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

int indexOf(vector<pair<int, int>> vec, pair<int, int> p) {
	int index = -1;
	vector< pair<int, int> >::iterator i;
	for (i = vec.begin(); i != vec.end(); ++i) {
		index++;
		if ((*i).first == p.first && (*i).second == p.second)
			return index;
	}
	return index;
}

// Prints shortest paths from src to all other vertices 
void Graph::shortestPath(int src)
{
	// Create a set to store vertices that are being 
	// prerocessed 
	vector< pair<int, int> > setds;

	// Create a vector for distances and initialize all 
	// distances as infinite (INF) 
	vector<int> dist(V, INF);

	// Insert source itself in Set and initialize its 
	// distance as 0. 
	setds.push_back(make_pair(0, src));
	dist[src] = 0;

	/* Looping till all shortest distance are finalized
	then setds will become empty */
	while (!setds.empty())
	{
		// The first vertex in Set is the minimum distance 
		// vertex, extract it from set. 
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());

		// vertex label is stored in second of pair (it 
		// has to be done this way to keep the vertices 
		// sorted distance (distance must be first item 
		// in pair) 
		int u = tmp.second;

		// 'i' is used to get all adjacent vertices of a vertex 
		vector< graphEdge >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = (*i).end_ver;
			int weight = (*i).cost;

			// If there is shorter path to v through u. 
			if (dist[v] > dist[u] + weight)
			{
				/* If distance of v is not INF then it must be in
					our set, so removing it and inserting again
					with updated less distance.
					Note : We extract only those vertices from Set
					for which distance is finalized. So for them,
					we would never reach here. */
				if (dist[v] != INF) {
					pair<int, int> p = make_pair(dist[v], v);

					int index = indexOf(setds, p);
					if (index > -1)
						setds.erase(setds.begin() + index);
				}

				// Updating distance of v 
				dist[v] = dist[u] + weight;
				setds.push_back(make_pair(dist[v], v));
			}
		}
	}

	// Print shortest distances stored in dist[] 
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d -> %d \t\t %d\n", src, i, dist[i]);
}