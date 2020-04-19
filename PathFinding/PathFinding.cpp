/*
Write a Graph class that is built by reading a CSV file that defines a set of nodes and
each edge within a graph (see graph.csv). Your class should be able to read any csv in
this format to create your graph. On your class, create additionally the following functions:

isAcyclic - returns boolean whether the given graph is acyclic or if it contains cycles

DFS - looks for a value within the graph using DFS and returns the number of nodes visited
if found, or -1 if not found. Within the function, it should print the ordering of the nodes visited.

BFS - looks for a value within the graph using BFS and returns the number of nodes visited
if found, or -1 if not found. Within the function, it should print the ordering of the nodes visited.

topologicalSort - performs topological sort and prints the ordering of the nodes within the graph
(or returns a warning/error message if the graph is cyclic)

Important: This graph class will be used as the basis of an assignment to be given next week.
While it is due in 2 weeks' time, I suggest trying to get it done early so that you are not delayed
in starting the next assignment.

*********************
Building from your Graph class created in the last assignment,
implement two new functions for pathfinding within the graph:

Dijkstra - this function should accept a starting node and
a target node as input and return a list of nodes (as an array or vector)
representing the path from start to target using Dijkstra's algorithm.

Astar - this function should accept the same input and produce
the same output as Dijkstra(), but instead implements the A* pathfinding algorithm.

Run both of these algorithms using the "graph_astar.csv" file under Files on Canvas -
Note: this file differs from the previous graph in that it is NOT directed and
includes an additional "cost" for each connection in the graph;
this cost will need to be represented on your graph class to be utilized by
each of these pathfinding algorithms. Additionally, there is a node x and y coordinate
that should be used when calculating the heuristic in A*
*/

#include <iostream>
#include <fstream>
#include "graphType.h"
#include <vector>

using namespace std;

vector<graphEdge> readCSVFile(string file);
void printEdge(vector<graphEdge> edges);

int main()
{
	string file = "C:\\Bob\\graph_astar.csv";
	vector<graphEdge> edges;

	edges = readCSVFile(file);
	// printEdge(edges);

	Graph graph(8, edges);

	// print adjacency list representation of graph
	graph.printGraph();
		
	cout << "Shortest path to 2\n";
	graph.shortestPath(2);

	return 0;
}


vector<graphEdge> readCSVFile(string file) {

	vector<graphEdge> edges;
	ifstream infile;

	infile.open(file);

	if (!infile) {
		cerr << "Cannot open the input file." << endl;
		return edges;
	}

	char line[256];
	string cell = "";
	int i = 0;
	int j = 0;
	int col = 0;

	// skip the first line
	infile.getline(line, 256);

	while (infile.getline(line, 256))
	{
		graphEdge edge;
		col = 0;

		while (line[i])
		{
			if (line[i] != ',') {
				cell += line[i];
				j++;
			}
			else {
				int value = atoi(cell.c_str());

				switch (col)
				{
				case 0:
					edge.start_ver = value;
					break;
				case 1:
					edge.end_ver = value;
					break;
				case 2:
					edge.cost = value;
					break;
				case 3:
					edge.from_node_x = value;
					break;
				case 4:
					edge.from_node_y = value;
					break;
				case 5:
					edge.to_node_x = value;
					break;
				}
				col++;
				cell = "";
			}
			i++;
		}

		edge.to_node_y = atoi(cell.c_str());
		edges.push_back(edge);

		i = 0;
		j = 0;
		cell = "";
	}

	infile.close();
	return edges;
}


void printEdge(vector<graphEdge> edges) {
	vector<graphEdge>::iterator i;
	for (i = edges.begin(); i != edges.end(); ++i) {
		printf("(%d, %d, %d, %d, %d, %d, %d)\n", (*i).start_ver, 
			(*i).end_ver, (*i).cost, (*i).from_node_x, (*i).from_node_y, 
			(*i).to_node_x, (*i).to_node_y);
	}

	cout << "\n\n";
}