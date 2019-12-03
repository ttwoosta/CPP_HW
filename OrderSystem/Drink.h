#pragma once
#include "FoodBase.h"
class Drink :
	public FoodBase
{
public:
	Drink(string name, double price, int waitTime);
	string desc();
};

typedef Drink* DrinkPtr;