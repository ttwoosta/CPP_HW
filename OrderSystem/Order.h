#pragma once

#include <vector>
#include "OrderItem.h"

class Order
{
public:
	vector<OrderItemPtr> OrderItems;

	double subtotal();
	double tax();
	double total();
	int waitTime();
};

typedef Order* OrderPtr;