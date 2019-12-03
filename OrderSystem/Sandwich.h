#pragma once
#include "FoodBase.h"
class Sandwich :
	public FoodBase
{
public:
	Sandwich(string name, double price, int waitTime);
	string desc();
};

typedef Sandwich* SandwichPtr;
