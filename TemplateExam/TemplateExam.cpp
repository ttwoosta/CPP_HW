#include <iostream>
#include <string>
using namespace std;

int sum(int value1, int value2)
{
	int result;
	result = value1 + value2;
	return result;
}

float sum(float value1, float value2)
{
	float result;
	result = value1 + value2;
	return result;
}

string sum(string value1, string value2)
{
	string result;
	result = value1 + value2;
	return result;
}

template<class T> //or template<typename 
T Tsum(T value1, T value2)
{
	T result;
	result = value1 + value2;
	return result;

}

int main_disabled()
{
	int a, b;
	float c, d;
	string e, f;

	cout << "\n Enter 1st int value:";
	cin >> a;
	cout << "\n Enter 2nd int value:";
	cin >> b;
	cout << "\n using (int sum), The result of " << a << " + " << b << " is: " << sum(a, b) << endl;
	cout << "\n using (Tsum), The result of " << a << " + " << b << " is: " << Tsum(a, b) << endl;

	cout << "\n Enter 1st float value:";
	cin >> c;
	cout << "\n Enter 2nd float value:";
	cin >> d;
	cout << "\n using (float sum), The result of " << c << " + " << d << " is: " << sum(c, d) << endl;
	cout << "\n using (Tsum), The result of " << c << " + " << d << " is: " << Tsum(c, d) << endl;

	cout << "\n Enter 1st char value:";
	cin >> e;
	cout << "\n Enter 2nd char value:";
	cin >> f;
	cout << "\n using (string sum), The result of " << e << " + " << f << " is: " << sum(e, f) << endl;
	cout << "\n using (Tsum), The result of " << e << " + " << f << " is: " << Tsum(e, f) << endl;

	return 0;
}
