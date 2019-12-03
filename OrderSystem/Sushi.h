#pragma once
#include "FoodBase.h"
class Sushi :
	public FoodBase
{
public:
	Sushi(string name, double price, int waitTime);
	string desc();
};

typedef Sushi* SushiPtr;