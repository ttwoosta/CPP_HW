#include "Laptop.h"

Laptop::Laptop() {

}

Laptop::Laptop(string brand, int ram, int hdCapacity) {
	this->brand = brand;
	this->ram = ram;
	this->hdCapacity = hdCapacity;
}

string Laptop::desc() {
	return brand + ", HD: " + to_string(hdCapacity) + ",RAM: " + to_string(ram) + " GB";
}