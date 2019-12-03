#include "Sushi.h"


Sushi::Sushi(string name, double price, int waitTime) {
	this->name = name;
	this->price = price;
	this->waitTime = waitTime;
}

string Sushi::desc() {
	return "Sushi";
}