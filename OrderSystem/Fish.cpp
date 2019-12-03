#include "Fish.h"

Fish::Fish(string name, double price, int waitTime) {
	this->name = name;
	this->price = price;
	this->waitTime = waitTime;
}

string Fish::desc() {
	return "Fish";
}