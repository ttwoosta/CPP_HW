#pragma once
#include "FoodBase.h"
#include "Fish.h"

class Sushi :
	public FoodBase
{
public:
	Sushi(string name, FishPtr fish, double price);
	string FoodBase::desc();
	FishPtr fish;
};

typedef Sushi* SushiPtr;