#include <iostream>
#include <queue>

using namespace std;
int fact(int num);

int fact(int num)
{
	if (num <= 1) // base case
		return 1;
	else
		return num * fact(num - 1);
}

int main_disabled()
{
	//int x;
	cout << fact(3) << endl;
	cout << fact(1) << endl;
	cout << fact(4) << endl;
	cout << fact(7) << endl;
	return 0;
}
