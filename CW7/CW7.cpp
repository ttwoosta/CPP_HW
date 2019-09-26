// CW7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	// Declare variable N, the size of the stack
	int nTime = 0;
	// a float variable used for capture input value
	float enteredValue;
	// the stack
	stack<float> stack1;
	// the size of stack
	int sizeOfStack = 0;
	
	// prompt the user for enter the N value
	// then store the value into N
	cout << "Enter a N number: ";
	cin >> nTime;
	
	// prompt user N times for entering float values
	for (int i = 0; i < nTime; i++) {
		cout << "Please enter item #" << i+1 << ": ";
		cin >> enteredValue;
		stack1.push(enteredValue); // store float value to the stack
		sizeOfStack++;
	}

	// print out the size of the stack
	cout << "\nThe stack contains " << sizeOfStack << " items";

	// print out all items in stack1
	cout << "\n\nPrinting all the items in stack1:\n";
	while (!stack1.empty())
	{
		cout << '\t' << stack1.top() << endl;
		stack1.pop();
	}
	cout << '\n';

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
