#include "Meat.h"


Meat::Meat(string name, double price, int waitTime) {
	this->name = name;
	this->price = price;
	this->waitTime = waitTime;
}

string Meat::desc() {
	return "Meat";
}