#pragma once
#include "Food.h"

class Sushi :
	public Food
{
public:
	Sushi(string name, string kind_of_fish, double price);
	string kind_of_fish;
	string Food::desc();
};

