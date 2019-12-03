#pragma once
#include "OrderItem.h"
#include "Drink.h"

class DrinkOrderItem :
	public OrderItem
{
public:
	DrinkOrderItem(DrinkPtr drink, int quality);
	string desc();
	int waitTime();
	double cost();
};

