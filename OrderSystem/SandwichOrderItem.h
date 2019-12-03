#pragma once
#include <vector>
#include "OrderItem.h"
#include "Bread.h"
#include "Sandwich.h"

class SandwichOrderItem :
	public OrderItem
{
public:
	vector<FoodPtr> components;

	SandwichOrderItem(SandwichPtr sandwich, int quality);
	string desc();
	int waitTime();
	double cost();
};

typedef SandwichOrderItem* SandwichOrderItemPtr;