#pragma once

#include "FoodBase.h"

class Fish:
	public FoodBase
{
public:
	Fish(string name, double price, int waitTime);
	string desc();
};

typedef Fish* FishPtr;
