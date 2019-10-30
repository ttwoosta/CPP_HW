// PointerAndClasses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void Exam1();
void Exam2();
void DynamicArray();

int main()
{
	int i = 1;

	
	while (i > 0)
	{
		cout << "Please enter example number: ";
		cin >> i;

		switch (i)
		{
		case 1:
			Exam1();
			break;
		case 2:
			Exam2();
			break;
		case 3:
			DynamicArray();
			break;
		default:
			break;
		}
	}
		
	return 0;
}

void Exam1() {
	int* p;
	int num;

	num = 78;
	p = &num;

	cout << "The address of p: " << &p << endl;
	cout << "The content of p: " << p << endl;
	cout << "The content of memory location p pointing to: " << *p << endl;
	cout << "--------------------------------------\n";
	cout << "The value of num: " << num << endl;
	cout << "The value of p: " << *p << endl;
	cout << "--------------------------------------\n";
	*p += 20;
	cout << "Changing value of pointer p" << endl;
	cout << "The value of num: " << num << endl;
	cout << "The value of p: " << *p << endl;
	cout << "--------------------------------------\n";
	num -= 20;
	cout << "Changing value of num" << endl;
	cout << "The value of num: " << num << endl;
	cout << "The value of p: " << *p << endl;
}

void Exam2() {
	int* p;			// p is the pointer of type int
	char* name;		// name is the pointer of type char
	string* str;    // str is the pointer of type string

	p = new int;
	*p = 28;
	
	name = new char[5];
	name[0] = 'J';

	str = new string;
	*str = "Sunny Day";

	cout << "The value of pointer p: " << *p << endl;
	cout << "The value of pointer name: " << *name << endl;
	cout << "The value off pointer str: " << *str << endl;

	delete p;
	delete []name; // must delete with scalar
	delete str;
}

void DynamicArray() {
	int* intList;
	int arraySize;

	cout << "Enter the array size: ";
	cin >> arraySize;
	cout << endl;

	intList = new int[arraySize];
	intList[0] = 12;
	intList[3] = 57;

	cout << "The value of int list at 0: " << intList[0] << endl;
	cout << "The value of int list at 3: " << intList[3] << endl;

	delete[] intList;
}