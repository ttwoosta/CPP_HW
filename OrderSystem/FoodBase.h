
/*
	Base class
*/
#pragma once
#include <string>
using namespace std;

class FoodBase
{
public:
	int id;
	string name;
	double price;
	int waitTime;
	virtual string desc();
};

typedef FoodBase* FoodPtr;
