#include "SushiOrderItem.h"


SushiOrderItem::SushiOrderItem(SushiPtr sushi, FishPtr fish, int quality) {
	this->name = sushi->name;
	this->food = sushi;
	this->fish = fish;
	this->quality = quality;
}

string SushiOrderItem::desc() {
	string name = "Sushi: " + this->name;
	if (this->fish)
		name += " + " + this->fish->name;
	return name;
}

int SushiOrderItem::waitTime() {
	int waitTime = this->food->waitTime;
	if (this->fish)
		waitTime += this->fish->waitTime;
	return waitTime;
}

double SushiOrderItem::cost() {
	double price = this->food->price;
	if (this->fish)
		price += this->fish->price;
	return price * this->quality;
}