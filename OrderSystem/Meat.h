#pragma once

#include "FoodBase.h"

class Meat : public FoodBase
{
public:
	Meat(string name, double price, int waitTime);
	string desc();
};

typedef Meat* MeatPtr;