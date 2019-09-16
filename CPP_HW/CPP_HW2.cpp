// CPP_HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Book
{
	int bookNumber;
	string title;
	string authorLastName;
	string publisher;
	int numberOfPages;
	double price;

	Book* link;
};

int main()
{
	Book *head = new Book();
	head->bookNumber = 12323132;
	head->title = "Linked list";
	head->authorLastName = "Tong";
	head->publisher = "Tu Tong";
	head->numberOfPages = 1000;
	head->price = 300;

	cout << "My book " + head->title << "\n";
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
