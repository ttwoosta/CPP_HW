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
    string file = "C:\\Bob\\graph.csv";
	vector<graphEdge> edges;

	edges = readCSVFile(file);

	// print adjacency list representation of graph
	printEdge(edges);
	
	Graph graph(8, edges);

	cout << "Depth First Search\n";
	graph.DFS(2);
	cout << endl;

	cout << "Breadth First Search\n";
	graph.BFS(2);
	cout << endl;

	cout << "Topological Sort\n";
	graph.topologicalSort();

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

	// skip the first line
	infile.getline(line, 256);

	while (infile.getline(line, 256))
	{
		graphEdge edge;

		while (line[i])
		{
			if (line[i] != ',') {
				cell += line[i];
				j++;
			}
			else {
				edge.start_ver = atoi(cell.c_str());
				cell = "";
			}
			i++;
		}

		edge.end_ver = atoi(cell.c_str());
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
	for (i = edges.begin(); i != edges.end(); ++i)
		cout << "(" << (*i).start_ver << "," << (*i).end_ver << ") ";

	cout << "\n\n";
}