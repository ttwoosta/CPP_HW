// Inheritance example 


#include <iostream> 
using namespace std;

class bankAccount
{
public:
	double balance;

	double virtual new_balance() {
		return 0;
	}
};

class CheckingAccount : public bankAccount
{
public:
	int number_of_checkbooks;
public:
	double total_cost() {
		return number_of_checkbooks * 14.99;
	}

	double new_balance() {
		return balance - (number_of_checkbooks * 14.99);
	}
};


class SavingAccount : public bankAccount
{
public:
	double interest_rate;
	int number_of_saving_years;
public:
	double new_balance() {
		double new_bl = balance;
		for (int i = 0; i < number_of_saving_years; i++)
		{
			new_bl += new_bl * interest_rate;
		}
		return new_bl;
	}
};

int main()
{

	CheckingAccount account1;
	SavingAccount account2;
	
	account1.balance = 1500.00;
	account1.number_of_checkbooks = 2;

	account2.balance = 400.00;
	account2.interest_rate = 0.057;
	account2.number_of_saving_years = 2;
	
	cout << "number of checkbooks of account1 is $" << account1.number_of_checkbooks << endl;
	cout << "balance of account1 is $" << account1.new_balance() << endl;
	cout << "total cost is $" << account1.total_cost() << endl;
	
	cout << "number of saving years is " << account2.number_of_saving_years << endl;
	cout << "balance of account2 is $" << account2.balance << endl;
	cout << "number of interest rate is " << account2.interest_rate * 100 << "%" << endl;
	cout << "new balance of account2 is $" << account2.new_balance() << endl;

	//cout << "balance of account3 is " << account3.balance << endl;

	return 0;
}
