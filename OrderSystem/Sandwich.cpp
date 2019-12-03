#include "Sandwich.h"


Sandwich::Sandwich(string name, double price, int waitTime) {
	this->name = name;
	this->price = price;
	this->waitTime = waitTime;
}

string Sandwich::desc() {
	return "Sandwich";
}