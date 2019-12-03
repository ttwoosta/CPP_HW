#include "Database.h"

Database::Database(string path) {
	// declare variables
	dbLine line;
	ifstream inFile;
	string typeStr;

	// open file
	inFile.open(path);

	// read the first line
	inFile >> line.type >> line.name >> line.price >> line.waitTime;

	if (!inFile) {
		cout << "The database file could not be found. "
			<< "The program will terminates" << endl;
		inFile.close();
		return;
	}

	while (inFile)
	{
		typeStr = string(line.type);
		if (typeStr == "Bread") {
			BreadPtr bread = new Bread(line.name, line.price, line.waitTime);
			bread->id = breads.size() + 1;
			this->breads.push_back(bread);
		}
		else if (typeStr == "Meat") {
			MeatPtr meat = new Meat(line.name, line.price, line.waitTime);
			meat->id = meats.size() + 1;
			this->meats.push_back(meat);
		}
		else if (typeStr == "Fish") {
			FishPtr fish = new Fish(line.name, line.price, line.waitTime);
			fish->id = fishes.size() + 1;
			this->fishes.push_back(fish);
		}
		else if (typeStr == "Vegetable") {
			VegPtr veg = new Vegetable(line.name, line.price, line.waitTime);
			veg->id = veges.size() + 1;
			this->veges.push_back(veg);
		}
		else if (typeStr == "Drink") {
			DrinkPtr drink = new Drink(line.name, line.price, line.waitTime);
			drink->id = drinks.size() + 1;
			this->drinks.push_back(drink);
		}
		else if (typeStr == "Sushi") {
			SushiPtr sushi = new Sushi(line.name, line.price, line.waitTime);
			sushi->id = sushies.size() + 1;
			this->sushies.push_back(sushi);
		}
		else if (typeStr == "Sandwich") {
			SandwichPtr sandwich = new Sandwich(line.name, line.price, line.waitTime);
			sandwich->id = sandwiches.size() + 1;
			this->sandwiches.push_back(sandwich);
		}

		inFile >> line.type >> line.name >> line.price >> line.waitTime;
	}

	// close the file and exit
	inFile.close();
}