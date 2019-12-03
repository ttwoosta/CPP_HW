/*
Program Name:	Restaurant Order System
Author:			Tu Tong
Date:			December 01, 2019
Purpose: The Restaurant Order System places order by enter a number
		 key correspond to a item on menu. It includes 3 menus Sushi, 
		 Sandwich and Drink. The invoice shows order items and the total.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "MainHeader.h"
using namespace std;

// The function prints title string at the center of line
// with specified spacing
void printTitle(string title, int spacingLen);

// The function prints title string at the center of line
void printTitle(string title);

// The function prints an Invoice of the specified order
void printInvoice(OrderPtr order);

// The function prints all food elements of an array of FoodBase with 
// key correspond to index of the item
void printFoodMenu(vector<FoodPtr> foods, string title);

// The function takes double value and return currency string
string format_currency(double var);

// The function prints an sample Invoice on screen
int debug_sample_invoice(DatabasePtr db);
void debug_foods(vector<FoodPtr> foods);
int debug_database(DatabasePtr db);

// The function prompts the user for enter quality of order item
int how_many(string name);

// The function prints a menu and prompt the user to enter a number
FoodPtr component_menu(vector<FoodPtr> components, string menuTitle, string dishName);

// The function prints Sushi menu
OrderItemPtr sushi_menu(vector<FoodPtr> sushies, vector<FoodPtr> fishes);

// The function prints Sandwich menu
OrderItemPtr sandwich_menu(vector<FoodPtr> sandwiches, vector<FoodPtr> breads,
	vector<FoodPtr> meats, vector<FoodPtr> veges);

// The function prints Drink menu
OrderItemPtr drink_menu(vector<FoodPtr> drinks);

int main()
{
	// Initalize the database from text file
	DatabasePtr db = new Database("..\\FoodDatabase.txt");
	
	// Declare variables
	OrderPtr order = new Order();
	OrderItemPtr item;
	int keyVal = 0;

	// Printing Welcome header
	printTitle("");
	printTitle("Welcome to my restaurant");
	printTitle("");

	while (keyVal >= 0)
	{
		int numberOfItems = order->OrderItems.size();
		
		cout << "\n\n";
		printTitle("Main Menu");
		cout << " 1. Sushi menu" << endl;
		cout << " 2. Sandwich menu" << endl;
		cout << " 3. Drink menu" << endl;
		cout << " 7. Print Sample Invoice" << endl;
		if (order->OrderItems.size() > 0) {
			cout << " 8. Place the order (" << numberOfItems << " items)" << endl;
		}
		cout << " 9. Exit" << endl;

		cout << "\nPlease choose your menu: ";
		cin >> keyVal;

		switch (keyVal)
		{
		case 1:
			item = sushi_menu(db->sushies, db->fishes);
			if (item != NULL)
				order->OrderItems.push_back(item);
			break;
		case 2:
			item = sandwich_menu(db->sandwiches, db->breads, db->meats, db->veges);
			if (item != NULL)
				order->OrderItems.push_back(item);
			break;
		case 3:
			item = drink_menu(db->drinks);
			if (item != NULL)
				order->OrderItems.push_back(item);
			break;
		case 7:
			debug_sample_invoice(db);
			cin >> keyVal;
			break;
		case 8:
			printTitle("");
			printTitle("Your order");
			printTitle("");
			printInvoice(order);
			cin >> keyVal;
			break;
		case 9:
			return keyVal;
			break;
		}

		cin.clear();
		cin.ignore(200, '\n');
		system("CLS");
	}

	printTitle("Order Completed! Bye Bye");

	delete order;
	delete db;
	return 0;
}

void printTitle(string title, int spacingLen) {
	int len = spacingLen - title.length();
	int side1, side2;

	if ((len % 2) == 1) {
		len += 1;
		side1 = (len / 2) - 1;
		side2 = len / 2;
	}
	else
		side1 = side2 = len / 2;

	string sideStr1, sideStr2 = "";
	for (int i = 0; i < side1; i++)
		sideStr1 += "-";
	for (int i = 0; i < side2; i++)
		sideStr2 += "-";

	if (title.length() > 0)
		title = " " + title + " ";
	else
		title = "--";

	cout << sideStr1 << title << sideStr2 << endl;
}

void printTitle(string title) {
	printTitle(title, 50);
}

void printInvoice(OrderPtr order) {

	system("CLS");
	cout << "\n\n";
	printTitle("INVOICE", 74);
	cout << setfill(' ') << left << setw(7) << "Item#"
		<< setw(10) << "Type"
		<< setw(25) << "Description"
		<< setw(7) << "Price"
		<< setw(8) << "Quality"
		<< setw(10) << "Subtotal"
		<< setw(10) << "Wait Time"
		<< endl;
	cout << setfill('-') << right << setw(7) << " "
		<< setw(10) << " "
		<< setw(25) << " "
		<< setw(7) << " "
		<< setw(8) << " "
		<< setw(10) << " "
		<< setw(10) << " "
		<< endl;

	for (int i = 0; i < (int)order->OrderItems.size(); i++)
	{
		OrderItemPtr item1 = order->OrderItems[i];

		FoodPtr food1 = item1->food;
		vector<FoodPtr> comps;

		if (typeid(*item1) == typeid(SushiOrderItem)) {
			FishPtr fish = ((SushiOrderItemPtr)item1)->fish;
			if (fish != NULL)
				comps.push_back(fish);
		}
		else if (typeid(*item1) == typeid(SandwichOrderItem)) {
			comps = ((SandwichOrderItemPtr)item1)->components;
		}

		cout << setfill(' ') << right
			<< setw(3) << i + 1
			<< setw(4) << ""
			<< left
			<< setw(10) << item1->food->desc()
			<< setw(25) << item1->food->name
			<< right << setw(6) << format_currency(item1->food->price)
			<< right << setw(8) << item1->quality
			<< right << setw(10) << format_currency(item1->food->price * item1->quality)
			<< right << setw(10) << item1->food->waitTime
			<< endl;
		for (int j = 0; j < (int)comps.size(); j++)
		{
			FoodPtr food2 = comps[j];
			cout << setfill(' ') << left << setw(7) << ""
				<< setw(10) << food2->desc()
				<< setw(25) << food2->name
				<< right << setw(6) << format_currency(food2->price)
				<< right << setw(8) << item1->quality
				<< right << setw(10) << format_currency(food2->price * item1->quality)
				<< right << setw(10) << food2->waitTime
				<< endl;
		}
	}

	cout << setfill('-') << right << setw(7) << " "
		<< setw(10) << " "
		<< setw(25) << " "
		<< setw(7) << " "
		<< setw(8) << " "
		<< setw(10) << " "
		<< setw(10) << " "
		<< endl;

	cout << setfill(' ') << right << setw(7) << " "
		<< setw(10) << " "
		<< setw(25) << " "
		<< setw(7) << " "
		<< setw(8) << " "
		<< setw(9) << format_currency(order->subtotal())
		<< setw(10) << order->waitTime()
		<< endl;

	cout << "\n";
	cout << setfill(' ') << right 
		<< setw(55) << "Please wait: " 
		<< left << order->waitTime() << " minutes\n\n";

	cout << setfill(' ') << right 
		<< setw(55) << "Subtotal: " 
		<< setw(10) << format_currency(order->subtotal()) << endl;
	cout << setfill(' ') << right
		<< setw(55) << "Tax (6.25%): "
		<< setw(10) << format_currency(order->tax()) << endl;
	cout << setfill(' ') << right
		<< setw(55) << "" 
		<< setfill('-')	<< setw(10) << "" << endl;
	cout << setfill(' ') << right
		<< setw(55) << "Your Total: "
		<< setw(10) << format_currency(order->total()) << endl;
	
	cout << "\n\nPress any key to return to Main Menu\n";
}

void printFoodMenu(vector<FoodPtr> foods, string title) {
	system("CLS");
	cout << "\n\n";
	printTitle(title, 35);
	cout << setfill(' ') << left 
		<< setw(7) << "Item#"
		<< setw(25) << "Description"
		<< setw(7) << "Price"
		<< endl;
	cout << setfill('-') << right 
		<< setw(7) << " "
		<< setw(25) << " "
		<< setw(7) << " "
		<< endl;

	for (int i = 0; i < (int)foods.size(); i++)
	{
		FoodPtr food = foods[i];

		cout << setfill(' ') << right 
			<< setw(3) << i + 1
			<< setw(4) << ""
			<< left << setw(25) << food->name
			<< format_currency(food->price)
			<< endl;
	}
}

string format_currency(double var)
{
	// we use array of chars to store number 
	// as a string. 
	char str[40];

	const char* format = "$%.2f";

	// Print in string the value of var  
	// with two decimal point 
	sprintf_s(str, format, var);

	return str;
}

int debug_sample_invoice(DatabasePtr db) {
	OrderPtr order = new Order();

	order->OrderItems.push_back(new SushiOrderItem((SushiPtr)db->sushies[0],
		(FishPtr)db->fishes[1], 2));
	order->OrderItems.push_back(new SushiOrderItem((SushiPtr)db->sushies[2],
		(FishPtr)db->fishes[5], 3));

	SandwichOrderItemPtr sw1 = new SandwichOrderItem((SandwichPtr)db->sandwiches[0], 1);
	sw1->components.push_back(db->breads[1]);
	sw1->components.push_back(db->meats[2]);
	sw1->components.push_back(db->veges[2]);
	order->OrderItems.push_back(sw1);

	order->OrderItems.push_back(
		new DrinkOrderItem((DrinkPtr)db->drinks[1], 1));
	order->OrderItems.push_back(
		new DrinkOrderItem((DrinkPtr)db->drinks[5], 1));

	printInvoice(order);

	return 0;
}

void debug_foods(vector<FoodPtr> foods) {
	for (int i = 0; i < (int)foods.size(); i++)
	{
		FoodPtr food = foods[i];
		cout << to_string(food->id) + ". " << setfill('.') << left << setw(35) <<
			food->name << right << " $" << food->price << endl;
	}
}

int debug_database(DatabasePtr db) {
	int value = 0;

	while (value >= 0)
	{
		printTitle("Debugging");
		cout << "1. Bread menu" << endl;
		cout << "2. Meat menu" << endl;
		cout << "3. Fish menu" << endl;
		cout << "4. Vegetable menu" << endl;
		cout << "5. Drink menu" << endl;
		cout << "6. Sushi menu" << endl;
		cout << "7. Sandwich menu" << endl;
		cout << "8. Return to main menu" << endl;

		cin >> value;
		switch (value)
		{
		case 1:
			debug_foods(db->breads);
			break;
		case 2:
			debug_foods(db->meats);
			break;
		case 3:
			debug_foods(db->fishes);
			break;
		case 4:
			debug_foods(db->veges);
			break;
		case 5:
			debug_foods(db->drinks);
			break;
		case 6:
			debug_foods(db->sushies);
			break;
		case 7:
			debug_foods(db->sandwiches);
			break;
		case 8:
			return value;
			break;
		default:
			break;
		}

		cin.clear();
		cin.ignore(200, '\n');
	}

	return 1;
}

int how_many(string name) {
	int value = 0;

	while (value >= 0)
	{
		cout << "\n\nHow many of " + name + " would you like?: ";
		cin >> value;

		if (value > 0) {
			return value;
		}
		
		cin.clear();
		cin.ignore(200, '\n');
	}

	return 0;
}

OrderItemPtr drink_menu(vector<FoodPtr> drinks) {
	int value = 0;

	while (value >= 0)
	{
		printFoodMenu(drinks, "Drink Menu");
		cout << "  9. Return to main menu" << endl;
		cout << "Please choose your drink: ";
		cin >> value;

		if (value == 9) {
			return NULL;
		}
		else if (value > 0 && value <= (int)drinks.size()) {
			DrinkPtr drink = (DrinkPtr)drinks[value - 1];
			int quality = how_many(drink->name);
			OrderItemPtr item = new DrinkOrderItem(drink, quality);

			return item;
		}

		cin.clear();
		cin.ignore(200, '\n');
	}

	return NULL;
}

FoodPtr component_menu(vector<FoodPtr> components, string menuTitle, string dishName) {
	int value = 0;

	while (value >= 0)
	{
		printFoodMenu(components, menuTitle);
		cout << "  9. Return to main menu" << endl;
		cout << "Please choose your add-on to " + dishName + ": ";

		cin >> value;

		if (value == 9) {
			return 0;
		}
		else if (value > 0 && value <= (int)components.size()) {
			return components[value - 1];
		}

		cin.clear();
		cin.ignore(200, '\n');
	}

	return NULL;
}

OrderItemPtr sandwich_menu(vector<FoodPtr> sandwiches, vector<FoodPtr> breads,
	vector<FoodPtr> meats, vector<FoodPtr> veges) {
	int value = 0;

	while (value >= 0)
	{
		printFoodMenu(sandwiches, "Sandwich Menu");
		cout << "  9. Return to main menu" << endl;
		cout << "Please choose your sandwich: ";
		cin >> value;

		if (value == 9) {
			return NULL;
		}
		else if (value > 0 && value <= (int)sandwiches.size()) {
			SandwichPtr sandwich = (SandwichPtr)sandwiches[value - 1];
			BreadPtr bread = (BreadPtr)component_menu(breads, "Bread Menu", sandwich->name);
			MeatPtr meat = (MeatPtr)component_menu(meats, "Meat Menu", sandwich->name);
			VegPtr vege = (VegPtr)component_menu(veges, "Vegetable Menu", sandwich->name);
			int quality = how_many(sandwich->name + " Sandwich");
			SandwichOrderItemPtr item = new SandwichOrderItem(sandwich, quality);
			if (bread)
				item->components.push_back(bread);
			if (meat)
				item->components.push_back(meat);
			if (vege)
				item->components.push_back(vege);
			return item;
		}

		cin.clear();
		cin.ignore(200, '\n');
	}

	return NULL;
}

OrderItemPtr sushi_menu(vector<FoodPtr> sushies, vector<FoodPtr> fishes) {
	int value = 0;

	while (value >= 0)
	{
		printFoodMenu(sushies, "Sushi Menu");
		cout << "  9. Return to main menu" << endl;
		cout << "Please choose sushi roll: ";
		cin >> value;

		if (value == 9) {
			return NULL;
		}
		else if (value > 0 && value <= (int)sushies.size()) {
			SushiPtr sushi = (SushiPtr)sushies[value - 1];
			FishPtr fish = (FishPtr)component_menu(fishes, "Fish Menu", sushi->name);
			int quality = how_many(sushi->name + " Roll");
			OrderItemPtr item = new SushiOrderItem(sushi, fish, quality);

			return item;
		}

		cin.clear();
		cin.ignore(200, '\n');
	}

	return NULL;
}