#include "LinkedListGraph.h"
#include <iostream>


template<class vType>
void LinkedListGraph<vType>::getAdjacentVerticies(vType adjacencyList[], int& length)
{
	nodeType<vType>* current;

	length = 0;
	current = this->first;

	while (current != NULL)
	{
		adjacencyList[length++] = current->info;
		current = current->link;
	}
}

template<class vType>
void LinkedListGraph<vType>::print()
{
	nodeType<vType>* current;

	current = this->first;

	while (current != NULL)
	{
		cout << current;
		current = current->link;
	}
}
