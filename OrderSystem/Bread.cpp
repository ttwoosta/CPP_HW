#include "Bread.h"


Bread::Bread(string name, double price, int waitTime) {
	this->name = name;
	this->price = price;
	this->waitTime = waitTime;
}

string Bread::desc() {
	return "Bread";
}