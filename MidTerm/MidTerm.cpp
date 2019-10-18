// MidTerm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Laptop.h"
#include <queue>
#include <stack>

using namespace std;

int main()
{
	queue<LaptopPtr> laptops;
	queue<Laptop*> laptops1;
	Laptop laptops3[1]; // Parameterless contructor
	vector<LaptopPtr> vectorLaps;
	stack<Laptop> stackLaps;
	Laptop single;

	laptops.push(new Laptop("My Laptop", 256, 512));
	laptops1.push(new Laptop("Laptop 1", 256, 512));
	laptops3[0].brand = "Laptop new model";
	laptops3[0].ram = 256;
	laptops3[0].hdCapacity = 512;
	vectorLaps.push_back(new Laptop("New model laptop", 128, 256));
	
	single.brand = "Hello";
	single.ram = 128;
	single.hdCapacity = 256;
	stackLaps.push(single);

    cout << laptops.front()->desc() << endl;
	cout << laptops1.front()->desc() << endl;
	cout << laptops3[0].desc() << endl;
	cout << vectorLaps.front()->desc() << endl;
	cout << stackLaps.top().desc() << endl;
}

