/*
	CPTR 2300 W01 Data Structures
	Assignment: Homework 4
	Date: 10/22/2019
	Purpose: The program prompt the user to place an order by enter number from 1 to 6
	that correspond to food item in database.
	The user complete the order by enter a negative number. The program print completed
	kind order Food have been ordered and the total of the order.
*/
#include <iostream>
#include <vector>
#include "Food.h"
#include "Sandwich.h"
#include "Sushi.h"
#include <iomanip>
using namespace std;

int main()
{
	vector<FoodPtr> foodDb;
	foodDb.push_back(new Sandwich("Buffalo Chicken", "Italian", 3.97));
	foodDb.push_back(new Sandwich("Italian B.M.T", "French", 7.29));
	foodDb.push_back(new Sandwich("Meatball Merinara", "Canadian", 4.83));
	foodDb.push_back(new Sushi("Rainbow Roll", "Salmon", 5.99));
	foodDb.push_back(new Sushi("Spicy Tuna Roll", "Tuna", 7.50));
	foodDb.push_back(new Sushi("Zen Roll", "Eel", 6.45));
	
	int dbSize = foodDb.size();
	int value = 0;
	FoodPtr food;
	vector<FoodPtr> order;
	double orderTotal = 0;

	cout << "*************************************************" << endl;
	cout << "Welcome to my restaurant" << endl;
	cout << "*************************************************" << endl;
	cout << "Enter a negative number to complete the order" << endl;

	while (value >= 0)
	{
		cout << "Please enter a value from 1 to " + to_string(dbSize) + ":  ";
		cin >> value;
		if (value < 0)
			break;
		else if (value > dbSize) {
			cout << "You entered invalid number" << endl;
			continue;
		}

		food = foodDb[value-1];
		cout << food->desc() << endl;
		order.push_back(food);
	}

	cout << "\n\n*************************************************" << endl;

	for (int i = 0; i < order.size(); i++)
	{
		food = order[i];
		orderTotal += food->price;
		cout << setfill('.') << left << setw(35) << food->name
			<< right << " $" << food->price << endl;
	}

	cout << setfill('.') << left << setw(35) << "Your total is: "
		<< right << " $" << orderTotal << endl;

	return 0;
}

