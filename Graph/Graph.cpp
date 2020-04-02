// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GraphType.h"

using namespace std;

int main()
{

	GraphType<linkedListType<int>, 10> graph;

	graph.createGraph();
	//graph.printGraph();

	for (int i = 0; i < 10; i++)
	{
		cout << i << " " << graph[i].print() << endl;
	}

	cout << endl;

	return 0;
}

