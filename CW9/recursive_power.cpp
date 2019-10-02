#include <iostream>
using namespace std;

int power(int x, int n);

int main_power()
{
	cout << power(3, 4) << endl;
	return 0;
}

int power(int x, int n)
{
	if (n < 0)
	{
		cout << "Illegal argument to power.\n";
		exit(1);
	}
	if (n > 0)
		return (power(x, n - 1) * x);
	else // n == 0
		return (1);
}

