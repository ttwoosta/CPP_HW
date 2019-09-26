#include <iostream>
#include <queue>
using namespace std;

int main()
{

	queue<int> queue1, queue2;

	cout << " Queue: ";
	queue1.push(105);
	queue1.push(22);
	queue1.push(45);
	cout << "\n size of queue1: ";
	cout << queue1.size() << endl;

	cout << "\n size of queue2: ";
	cout << queue2.size() << endl;

	cout << "\n Printing the front item of queue1: ";
	cout << queue1.front() << endl;
	cout << "\n Printing the back item of queue1: ";
	cout << queue1.back() << endl;
	cout << "\n Printing all the items in queue1:\n";
	while (!queue1.empty())
	{
		cout << '\t' << queue1.front() << endl;;
		queue1.pop();
	}
	cout << '\n';


	queue2.push(30);
	cout << "\n size of queue1: " << queue1.size() << endl;
	cout << "\n size of queue2: " << queue2.size() << endl;
	cout << "\n is queue1 > queue2? " << endl;

	if (queue1 > queue2)
		cout << " queue1 is greater than queue2";
	else
		cout << " queue1 is less than queue2";

	return 0;
}