#include "Drink.h"


Drink::Drink(string name, double price, int waitTime) {
	this->name = name;
	this->price = price;
	this->waitTime = waitTime;
}

string Drink::desc() {
	return "Drink";
}