/*
Part 1: Write a recursive function that returns the sum of 
the squares of the numbers from 0 to N, in which N is a 
nonnegative int variable to be entered by the user.

Also write a main program to call and test the function .
Example of input/output:
Enter N:  5
Sum of squares from 0 to 5 = 55

Part 2: Re-write the program using iterations.
*/

#include <iostream>
#include <iomanip>
using namespace std;

void printLine(string label, int value);
int squareSumRecursive(int num);
int squareSum(int n);

int main()
{
	int x = 0;
	
	cout << "Enter 99 to stop the function" << endl;

	while (x != 99)
	{
		cout << "Please enter a the N: ";
		cin >> x;

		printLine("Square Sum recursively of N value is", squareSumRecursive(x));
		printLine("Square Sum non-recursive of N value is", squareSum(x));

		cout << "----------------------------------" << endl;
	}
	
	return 0;
}

void printLine(string label, int value) {
	cout << setfill('.') << left << setw(40) << label
		<< right << " " << value << endl;
}

// Recursively return the sum of the square
// of first n natural numbers
int squareSumRecursive(int num) {
	if (num <= 1) 
		// base case        
		return 1;    
	else
		return num*num + squareSumRecursive(num-1);
}

// Return the sum of the square
// of first n natural numbers
int squareSum(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += (i * i);
	return sum;
}