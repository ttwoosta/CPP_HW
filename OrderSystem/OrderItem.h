#pragma once

#include "FoodBase.h"

class OrderItem
{
public:
	FoodPtr food;
	int quality;
};

typedef OrderItem* OrderItemPtr;
