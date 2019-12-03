#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include "Bread.h"
#include "Drink.h"
#include "Fish.h"
#include "Order.h"
#include "OrderItem.h"
#include "SandwichOrderItem.h"
#include "SushiOrderItem.h"
#include "Meat.h"
#include "Vegetable.h"
#include "Sushi.h"
#include "Sandwich.h"
using namespace std;

struct dbLine
{
	char type[15];
	char name[15];
	double price;
	int waitTime;
};

class Database
{
public:
	vector<FoodPtr> breads;
	vector<FoodPtr> meats;
	vector<FoodPtr> fishes;
	vector<FoodPtr> veges;
	vector<FoodPtr> drinks;
	vector<FoodPtr> sushies;
	vector<FoodPtr> sandwiches;

	Database(string path);
};

typedef Database* DatabasePtr;