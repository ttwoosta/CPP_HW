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

int main()
{
	vector<int> listNum;
	generate_random_list(listNum, 10);

	BinaryTreePtr btree = new BinaryTree(listNum);

	btree->printDebug();
}

void generate_random_list(vector<int>& list, int n) {
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1, 99);
	list.clear();
	for (size_t i = 0; i < n; i++)
		// generates number in the range 1..n 
		list.push_back(distribution(generator));
}

