#include "Vegetable.h"


Vegetable::Vegetable(string name, double price, int waitTime) {
	this->name = name;
	this->price = price;
	this->waitTime = waitTime;
}

string Vegetable::desc() {
	return "Vege";
}