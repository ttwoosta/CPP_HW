#pragma once

#include "FoodBase.h"

class OrderItem
{
public:
	string name;
	FoodPtr food;
	int quality;

	virtual string desc();
	virtual int waitTime();
	virtual double cost();
};

typedef OrderItem* OrderItemPtr;
