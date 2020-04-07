// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GraphType.h"

using namespace std;

int main()
{

	GraphType<int, 10> graph;

	graph.createGraph();
	//graph.printGraph();

	

	cout << endl;

	return 0;
}

