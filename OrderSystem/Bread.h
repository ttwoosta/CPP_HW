#pragma once
#include "FoodBase.h"

class Bread: 
	public FoodBase
{
public:
	Bread(string name, double price, int waitTime);
	string desc();
};

typedef Bread* BreadPtr;



