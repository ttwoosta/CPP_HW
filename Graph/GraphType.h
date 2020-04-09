
#include "LinkedListGraph.h"
#include "linkedQueue.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
#pragma once

const int infinity = 10000000;

template<class vType, int size>
class GraphType
{
public:

	// default constructor
	GraphType();
	
	// default destructor
	~GraphType();

	// Function to determine whether the graph is empty
	bool isEmpty();
	
	// function to create the graph using the adjacency list
	void createGraph(string fileName);

	// function to deallocate the memory occupied by the 
	// linked list
	void clearGraph();

	void printGraph() const;

	void depthFirstTraversal();
	//Function to perform the depth first traversal of
	//the entire graph.
	//Postcondition: The vertices of the graph are printed 
	//    using the depth first traversal algorithm.

	void dftAtVertex(int vertex);
	//Function to perform the depth first traversal of 
	//the graph at a node specified by the parameter vertex.
	//Postcondition: Starting at vertex, the vertices are 
	//    printed using the depth first traversal algorithm.

	void breadthFirstTraversal();
	//Function to perform the breadth first traversal of
	//the entire graph.
	//Postcondition: The vertices of the graph are printed 
	//    using the breadth first traversal algorithm.

protected:
	int maxSize;	// maximun number of vertices
	int gSize;		// current number of vertices

	// array of pointer to create the adjacency list
	LinkedListGraph<vType> graph[size];

private:
	void dft(int v, bool visited[]);
	//Function to perform the depth first traversal of 
	//the graph at a node specified by the parameter vertex.
	//This function is used by the public member functions
	//depthFirstTraversal and dftAtVertex.
	//Postcondition: Starting at vertex, the vertices are 
	//    printed using the depth first traversal algorithm.
};

template<class vType, int size>
GraphType<vType, size>::GraphType()
{
	gSize = size;
	maxSize = size;
}

template<class vType, int size>
GraphType<vType, size>::~GraphType()
{
	clearGraph();
}

template<class vType, int size>
bool GraphType<vType, size>::isEmpty()
{
	return false;
}

template<class vType, int size>
void GraphType<vType, size>::createGraph(string fileName)
{
	ifstream infile;

	vType vertex;
	vType adjacentVertex;

	if (gSize != 0)  // if the graph is not empty, make it empty
		clearGraph();

	infile.open(fileName);

	if (!infile) {
		cerr << "Cannot open the input file." << endl;
		return;
	}

	char line[256];
	string cell;
	int i = 0;
	int j = 0;

	while (infile.getline(line, 256))
	{
		while (line[i])
		{
			if (line[i] != ',') {
				adjacentVertex = line[i] - '0';
				graph[j].insertLast(adjacentVertex);
				j++;
			}
			i++;
		}
	}
	
	infile.close();
}

template<class vType, int size>
void GraphType<vType, size>::clearGraph()
{
	for (int i = 0; i < gSize; i++)
	{
		graph[i].destroyList();
	}

	gSize = size;
}

template<class vType, int size>
void GraphType<vType, size>::printGraph() const
{
	cout << " ";

	for (int i = 0; i < 10; i++)
	{
		cout << graph[i].front() << "  ";
	}
	cout << endl;
}

template<class vType, int size>
void GraphType<vType, size>::depthFirstTraversal()
{
	bool* visited; //pointer to create the array to keep 
				   //track of the visited vertices
	visited = new bool[gSize];

	for (int index = 0; index < gSize; index++)
		visited[index] = false;

	//For each vertex that is not visited, do a depth 
	//first traverssal
	for (int index = 0; index < gSize; index++)
		if (!visited[index])
			dft(index, visited);
	delete[] visited;
} //end depthFirstTraversal

template<class vType, int size>
void GraphType<vType, size>::dft(int v, bool visited[])
{
	visited[v] = true;
	cout << " " << v << " ";  //visit the vertex

	linkedListIterator<int> graphIt;

	//for each vertex adjacent to v
	for (graphIt = graph[v].begin(); graphIt != graph[v].end();
		++graphIt)
	{
		int w = *graphIt;
		if (!visited[w])
			dft(w, visited);
	} //end while
} //end dft

template<class vType, int size>
void GraphType<vType, size>::dftAtVertex(int vertex)
{
	bool* visited;

	visited = new bool[gSize];

	for (int index = 0; index < gSize; index++)
		visited[index] = false;

	dft(vertex, visited);

	delete[] visited;
} // end dftAtVertex

template<class vType, int size>
void GraphType<vType, size>::breadthFirstTraversal()
{
	linkedQueueType<int> queue;

	bool* visited;
	visited = new bool[gSize];

	for (int ind = 0; ind < gSize; ind++)
		visited[ind] = false;	//initialize the array 
								//visited to false

	linkedListIterator<int> graphIt;

	for (int index = 0; index < gSize; index++)
		if (!visited[index])
		{
			queue.addQueue(index);
			visited[index] = true;
			cout << " " << index << " ";

			while (!queue.isEmptyQueue())
			{
				int u = queue.front();
				queue.deleteQueue();

				for (graphIt = graph[u].begin();
					graphIt != graph[u].end(); ++graphIt)
				{
					int w = *graphIt;
					if (!visited[w])
					{
						queue.addQueue(w);
						visited[w] = true;
						cout << " " << w << " ";
					}
				}
			} //end while
		}

	delete[] visited;
} //end breadthFirstTraversal