
#include "LinkedListGraph.h"
#include <iostream>
#include <fstream>

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
	void createGraph();

	// function to deallocate the memory occupied by the 
	// linked list
	void clearGraph();

	void printGraph() const;

protected:
	int maxSize;	// maximun number of vertices
	int gSize;		// current number of vertices

	// array of pointer to create the adjacency list
	LinkedListGraph<vType> graph[size];
};

template<class vType, int size>
GraphType<vType, size>::GraphType()
{
	gSize = 0;
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
void GraphType<vType, size>::createGraph()
{
	ifstream infile;
	string fileName;

	vType vertex;
	vType adjacentVertex;

	if (gSize != 0)  // if the graph is not empty, make it empty
		clearGraph();

	cout << "Enter the input file name: ";
	cin >> fileName;
	cout << endl;

	fileName = "c:\\Bob\\file.txt";

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
				graph[j].insertLast(line[i]);
				j++;
			}
			i++;
		}
	}

	cout << i;

	//infile >> gSize; // get the number of vertices

	//for (int i = 0; i < gSize; i++)
	//{
	//	infile >> vertex;
	//	infile >> adjacentVertex;

	//	while (adjacentVertex != 999)
	//	{
	//		graph[vertex].insertLast(adjacentVertex);
	//		infile >> adjacentVertex;
	//	}
	//}

	infile.close();
}

template<class vType, int size>
void GraphType<vType, size>::clearGraph()
{
	for (int i = 0; i < gSize; i++)
	{
		graph[i].destroyList();
	}

	gSize = 0;
}

template<class vType, int size>
void GraphType<vType, size>::printGraph() const
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << " ";
		this->graph[i].print();
		cout << endl;
	}
}
