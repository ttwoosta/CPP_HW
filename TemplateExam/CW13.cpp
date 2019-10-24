/*
	CW13: This is a template base functions
	Date: 10/23/2019
	Name: Tu Tong
*/

#include <iostream>
using namespace std;

// function maximum take 2 arguments of the same type
// and return the greater one
template <class T>
T maximum(T value1, T value2) {
	return (value1 > value2) ? value1 : value2;
}

// function minimun take 2 arguments of the same type
// and returns the smaller one
template <class T>
T minimun(T value1, T value2) {
	return (value1 < value2) ? value1 : value2;
}

// function absolute_value takes 2 arguments of the same type
// and return the absolute result of the subtraction
template <class T>
T absolute_value(T value1, T value2) {
	return abs(value1 - value2);
}

int main() {
	int v1 = 0, v2 = 0;
	float f1 = 0, f2 = 0;
	double d1 = 0, d2 = 0;

	cout << "========================INTEGER========================\n";
	cout << "Please enter integer value 1: ";
	cin >> v1;
	cout << "Please enter integer value 2: ";
	cin >> v2;
	cout << "The maximum is :" << maximum(v1, v2) << endl;
	cout << "The minimun is :" << minimun(v1, v2) << endl;
	cout << "The absolute is: " << absolute_value(v1, v2) << endl;
	cout << "==========================FLOAT======================\n" ;
	cout << "Please enter float value 1: ";
	cin >> f1;
	cout << "Please enter float value 2: ";
	cin >> f2;
	cout << "The maximum is :" << maximum(f1, f2) << endl;
	cout << "The minimun is :" << minimun(f1, f2) << endl;
	cout << "The absolute is: " << absolute_value(f1, f2) << endl;
	cout << "=========================DOUBLE=======================\n";
	cout << "Please enter double value 1: ";
	cin >> d1;
	cout << "Please enter double value 2: ";
	cin >> d2;
	cout << "The maximum is :" << maximum(d1, d2) << endl;
	cout << "The minimun is :" << minimun(d1, d2) << endl;
	cout << "The absolute is: " << absolute_value(d1, d2) << endl;
	cout << "================================================\n";

	return 0;
}