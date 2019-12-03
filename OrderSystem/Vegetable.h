#pragma once
#include "FoodBase.h"
class Vegetable :
	public FoodBase
{
public:
	Vegetable(string name, double price, int waitTime);
	string desc();
};

typedef Vegetable* VegPtr;