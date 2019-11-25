#include "Laptop.h"

Laptop::Laptop() {
	this->ram = 0;
	this->hdCapacity = 0;
	this->brand = "";
}

Laptop::Laptop(string brand, int ram, int hdCapacity) {
	this->brand = brand;
	this->ram = ram;
	this->hdCapacity = hdCapacity;
}

string Laptop::desc() {
	return brand + ", HD: " + to_string(hdCapacity) + ",RAM: " + to_string(ram) + " GB";
}