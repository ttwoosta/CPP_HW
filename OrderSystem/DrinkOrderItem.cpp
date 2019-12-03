#include "DrinkOrderItem.h"

DrinkOrderItem::DrinkOrderItem(DrinkPtr drink, int quality) {
	this->food = drink;
	this->quality = quality;
}

string DrinkOrderItem::desc() {
	return "Drink Order";
}

int DrinkOrderItem::waitTime() {
	return this->food->waitTime;
}

double DrinkOrderItem::cost() {
	return (this->food->price) * this->quality;
}