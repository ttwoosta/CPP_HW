
/*
	Base class
*/
#pragma once
#include <string>
using namespace std;

class Food
{
public:
	string name;
	double price;
	bool delivery;

	virtual string desc() = 0;
};

typedef Food* FoodPtr;