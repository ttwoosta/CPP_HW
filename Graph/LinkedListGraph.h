#pragma once

#include "linkedListType.h"

template<class vType>
class LinkedListGraph: virtual public linkedListType<vType>
{
public:
	
	// function to retrieve the vertices adjacent to a given
	// vertex.
	void getAdjacentVerticies(vType adjacencyList[], int& length);
};


