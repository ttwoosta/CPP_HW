
/*
	Base class
*/
#include <string>
using namespace std;

class FoodBase
{
public:
	string name;
	double price;
	bool delivery;

	virtual string desc() = 0;
};

typedef FoodBase* FoodPtr;
