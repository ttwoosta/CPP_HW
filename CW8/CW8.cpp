// CW8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	// declare a stack and a queue
	stack<char> chrStack;
	queue<char> chrQueue;
	string enteredWord = "";

	// prompt user for enter the word
	cout << "Enter a word: ";
	cin >> enteredWord;
	
	// iterate through the char in word and store them in stack
	for (int i = 0; i < enteredWord.length(); i++) {
		chrStack.push(enteredWord[i]);
	}

	// print out all items in char stack
	cout << "Printing all the items in char stack: ";
	while (!chrStack.empty())
	{
		cout << chrStack.top();
		chrStack.pop();
	}
	cout << "\n\n";

	// prompt user for enter the another word
	cout << "Enter another word: ";
	cin >> enteredWord;

	// store the letter of word into queue
	for (int i = 0; i < enteredWord.length(); i++) {
		chrQueue.push(enteredWord[i]);
	}

	// print out all items in char queue
	cout << "Printing all the items in char queue: ";
	while (!chrQueue.empty())
	{
		cout << chrQueue.front();
		chrQueue.pop();
	}
	cout << "\n\n";
		
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
