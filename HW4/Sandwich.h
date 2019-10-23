#pragma once
#include "Food.h"
class Sandwich :
	public Food
{
public:
	Sandwich(string name, string type_of_bread, double price);
	string type_of_bread;
	string Food::desc();
};

