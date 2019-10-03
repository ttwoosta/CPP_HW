/*
Write two recursive functions to print the following star shapes:
Shape 1:

* * * * *
* * * *
* * *
* *
*

Shape 2:
*
* *
* * *
* * * *
* * * * *
* * * * *
* * * *
* * *
* *
*

2. Write iterative version of the same program.
Comment your program and submit both parts in one cpp file here.
*/

#include <iostream>
#include <iomanip>
using namespace std;

void printStarRecursively(int x);
void printStarDecrementRecursively(int x, int limit);

void printStar(int x, bool backward);

int main()
{
	int x = 0;

	cout << "Enter 99 to stop the function" << endl;

	while (x != 99)
	{
		cout << "Please enter a the N: ";
		cin >> x;

		cout << "\n---------------Recursive----------" << endl;
		printStarRecursively(x);
		cout << "\n---------------Recursive--2nd-----" << endl;
		printStarDecrementRecursively(1, x);
		printStarRecursively(x);

		cout << "-------------Iteration--------------" << endl;
		printStar(x, false);
		cout << "-------------Iteration---2nd--------" << endl;
		printStar(x, false);
		printStar(x, true);
		cout << "\n----------------------------------" << endl;
	}

	return 0;
}

// print stars iteration forward/backward
void printStar(int x, bool backward) {
	for (int j = 0; j < x; j++) 
	{
		int limit = backward ? x - j : j;
		for (int i = 0; i < limit; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

// print stars recursively
void printStarRecursively(int x) {
	if (x > 0) {
		for (int i = 0; i < x; i++)
		{
			cout << "*";
		}
		cout << endl;
		printStarRecursively(x - 1);
	}
}

// print stars backward recursively 
void printStarDecrementRecursively(int x, int limit) {
	if (x < limit) {
		for (int i = 0; i < x; i++)
		{
			cout << "*";
		}
		cout << endl;
		printStarDecrementRecursively(x + 1, limit);
	}
}


