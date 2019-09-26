#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{

	stack<int> stack1, stack2;
	queue<int> queue1, queue2;

	cout << " Stack: ";
	stack1.push(105);
	stack1.push(22);
	stack1.push(45);
	cout << "\n size of stack1: ";
	cout << stack1.size() << endl;

	cout << "\n size of stack2: ";
	cout << stack2.size() << endl;

	cout << "\n Printing the top item of stack1: ";
	cout << stack1.top() << endl;

	cout << "\n Printing all the items in stack1:\n";
	while (!stack1.empty())
	{
		cout << '\t' << stack1.top() << endl;;
		stack1.pop();
	}
	cout << '\n';


	stack2.push(30);
	cout << "\n size of stack1: " << stack1.size() << endl;
	cout << "\n size of stack2: " << stack2.size() << endl;
	cout << "\n is stack1 > stack2? " << endl;

	if (stack1 > stack2)
		cout << " stack1 is greater than stack2";
	else
		cout << " stack1 is less than stack2";

	return 0;
}