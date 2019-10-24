/*
	CW14
	Write template-based function that takes array (size 10)
*/

#include <iostream>
using namespace std;

// template-based function that takes array (size 10) of any type
// and returns the maximum value among the ten elements
template <class T>
T maximum(T arr[]) {
	T maxVal = arr[0];
	for (int i = 1; i < 10; i++)
	{
		if (arr[i] > maxVal)
			maxVal = arr[i];
	}
	return maxVal;
}


int main()
{
	int arr1[] = { 10, 20, 15, 12, 87, 120, 33, 67, 9, 25 };
	cout << "The maximum value is: " << maximum(arr1) << endl;

	float arr2[] = { 5.5, 30.9,101.5, 3.2, 4.5, 23.8, 13.9, 78.8, 60.2, 50.0};
	cout << "The maximum value is: " << maximum(arr2) << endl;

	char arr3[] = { 't', 'e', 'c', 'h', 'n', 'o', 'l', 'o', 'g', 'y'};
	cout << "The maximum value is: " << maximum(arr3) << endl;

	return 0;
}

