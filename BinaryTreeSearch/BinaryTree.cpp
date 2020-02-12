#include "BinaryTree.h"
#include <iostream>


int FIND_MAX_VALUE(vector<int>& listNum) {
	int max = listNum[0];
	for (size_t i = 1; i < listNum.size(); i++)
	{
		if (listNum[i] > max)
			max = listNum[i];
	}
	return max;
}

int FIND_MIN_VALUE(vector<int>& listNum) {
	int min = listNum[0];
	for (size_t i = 1; i < listNum.size(); i++)
	{
		if (listNum[i] < min)
			min = listNum[i];
	}
	return min;
}

BinaryTree::BinaryTree(vector<int> listNum) {
	_listNum = listNum;

	int max = FIND_MAX_VALUE(listNum);
	int min = FIND_MIN_VALUE(listNum);

	root = new TreeNode(max);
}

void print_list(string desc, vector<int>& list) {
	cout << desc << ": ";
	for (size_t i = 0; i < list.size() - 1; i++)
		cout << list[i] << ",";
	cout << list[list.size() - 1] << endl;
}

void BinaryTree::printDebug() {
	print_list("List: ", _listNum);
	cout << "Binary Tree Root: " << this->root->value << endl;
}