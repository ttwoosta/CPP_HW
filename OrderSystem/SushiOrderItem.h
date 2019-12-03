#pragma once
#include "OrderItem.h"
#include "Fish.h"
#include "Sushi.h"

class SushiOrderItem :
	public OrderItem
{
public:
	FishPtr fish;

	SushiOrderItem(SushiPtr sushi, FishPtr fish, int quality);
	string desc();
	int waitTime();
	double cost();
};

typedef SushiOrderItem* SushiOrderItemPtr;