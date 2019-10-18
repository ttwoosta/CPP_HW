#pragma once
#include <string>
using namespace std;

class Laptop
{
public:
	string brand;
	int ram;
	int hdCapacity;

	Laptop();
	Laptop(string brand, int ram, int hdCapacity);
	string desc();
};

typedef Laptop* LaptopPtr;