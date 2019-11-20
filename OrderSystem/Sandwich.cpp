#include "Sandwich.h"


Sandwich::Sandwich(string name, string type_of_bread, double price) {
	this->name = name;
	this->price = price;
	this->type_of_bread = type_of_bread;
	delivery = true;
}

string Sandwich::desc() {
	return name + " " + type_of_bread + " $" + to_string(price);
}