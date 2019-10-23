#include "Sushi.h"

Sushi::Sushi(string name, string kind_of_fish, double price) {
	this->name = name;
	this->kind_of_fish = kind_of_fish;
	this->price = price;
	delivery = false;
}

string Sushi::desc() {
	return name + " " + kind_of_fish + " $" + to_string(price);
}