#include "Order.h"


int Order::waitTime() {
	int waitTime = 0;
	for (size_t i = 0; i < OrderItems.size(); i++)
	{
		waitTime += OrderItems[i]->waitTime();
	}
	return waitTime;
}

double Order::subtotal() {
	double cost = 0;
	for (size_t i = 0; i < OrderItems.size(); i++)
	{
		cost += OrderItems[i]->cost();
	}
	return cost;
}

double Order::tax() {
	return subtotal() * 0.0625;
}

double Order::total() {
	return subtotal() + tax();
}