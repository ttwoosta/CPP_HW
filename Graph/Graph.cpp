// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GraphType.h"

using namespace std;

int main()
{
	string fileName;

	cout << "Enter the input file name: ";
	cin >> fileName;
	cout << endl;

	fileName = "C:\\Bob\\file.txt";

	GraphType<int, 10> graph;

	graph.createGraph(fileName);

	cout << "Graph" << endl;
	graph.printGraph();
	
	cout << "\nDepth First Traversal" << endl;
	graph.depthFirstTraversal();

	cout << "\n\nBreadth First Traversal" << endl;
	graph.breadthFirstTraversal();
	

	return 0;
}

