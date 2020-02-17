/*
In C++, implement a binary search tree (BST) data structure with the following functionalities:

1). Create a function that is able to build a BST from a list (or vector) of integers.

2). Implement the INORDER-TREE-WALK function as a means of displaying the contents of the BST

3). Implement the TREE-SEARCH function
*/

#include <iostream>
#include "BinaryTree.h"
#include "TreeNode.h"
#include <random>

using namespace std;

void generate_random_list(vector<int>& list, int n);
void print_list(string desc, vector<int> list);
void print(TreeNodePtr node);

int main()
{
	int input;
	TreeNodePtr found;

	vector<int> listNum;
	generate_random_list(listNum, 10);
	print_list("Generated", listNum);
	BinaryTreePtr btree = new BinarySearchTree(listNum);

	cout << "\nIn-order walk: ";
	btree->inorderWalk(print);

	cout << "\n\nEnter an number to search: ";
	cin >> input;
	found = btree->search(input);
	if (found != NULL)
		cout << "Found a node" << endl;
	else
		cout << "Node with value " << input << " not found" << endl;
	
	return 0;
}

void print(TreeNodePtr node) {
	cout << node->value << " ";
}

void generate_random_list(vector<int>& list, int n) {
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1, 99);
	list.clear();
	for (size_t i = 0; i < n; i++)
		// generates number in the range 1..n 
		list.push_back(distribution(generator));
}

void print_list(string desc, vector<int> list) {
	cout << desc << ": ";
	for (size_t i = 0; i < list.size() - 1; i++)
		cout << list[i] << " ";
	cout << list[list.size() - 1] << endl;
}