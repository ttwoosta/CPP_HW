#pragma once
#include "FoodBase.h"
#include "Bread.h"
class Sandwich :
	public FoodBase
{
public:
	Sandwich(string name, BreadPtr bread, double price);
	string type_of_bread;
	string FoodBase::desc();

	BreadPtr bread;
};

typedef Sandwich* SandwichPtr;