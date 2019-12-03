#include "SandwichOrderItem.h"

SandwichOrderItem::SandwichOrderItem(SandwichPtr sandwich, int quality) {
	this->food = sandwich;
	this->name = sandwich->name;
	this->quality = quality;
}

string SandwichOrderItem::desc() {
	return "Sandwich Order";
}

int SandwichOrderItem::waitTime() {
	int waitTime = this->food->waitTime;
	for (size_t i = 0; i < components.size(); i++)
	{
		waitTime += components[i]->waitTime;
	}
	return waitTime;
}

double SandwichOrderItem::cost() {
	double price = this->food->price;
	for (size_t i = 0; i < components.size(); i++)
	{
		price += components[i]->price;
	}
	return price * this->quality;
}