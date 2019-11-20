#pragma once

#include <vector>
#include "OrderItem.h"

class Order
{
public:
	vector<OrderItemPtr> OrderItems;

};

typedef Order* OrderPtr;