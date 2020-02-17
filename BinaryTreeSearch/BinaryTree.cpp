#include "BinaryTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree(vector<int> listNum) {
	_listNum = listNum;
	TreeNodePtr newNode;

	for (size_t i = 0; i < listNum.size(); i++)
	{
		insert(listNum[i]);
	}
}

// Data Structure Using C++: D.S. Malik (p. 657)
void BinarySearchTree::insert(int insertNum) {
	
	TreeNodePtr current = NULL;
	TreeNodePtr trailCurrent = NULL;
	TreeNodePtr newNode;
	
	newNode = new TreeNode(insertNum);

	if (root == NULL) {
		root = newNode;
	}
	else {
		current = root;

		while (current != NULL)
		{
			trailCurrent = current;

			if (current->value == insertNum) {
				cerr << "The insert item is already in the list - ";
				cerr << "duplicates are not allows." << endl;
				return;
			}
			else {
				if (current->value > insertNum)
					current = current->leftNode;
				else
					current = current->rightNode;
			}
		}

		if (trailCurrent->value > insertNum)
			trailCurrent->leftNode = newNode;
		else
			trailCurrent->rightNode = newNode;
	}
}

void print_list(string desc, vector<int>& list) {
	cout << desc << ": ";
	for (size_t i = 0; i < list.size() - 1; i++)
		cout << list[i] << ",";
	cout << list[list.size() - 1] << endl;
}

// Data Structure Using C++: D.S. Malik (p. 673)
void BinarySearchTree::inorderWalk(void(*visit)(TreeNodePtr node)) {
	inorderWalk(root, *visit);
}

// Data Structure Using C++: D.S. Malik (p. 673)
void BinarySearchTree::inorderWalk(TreeNodePtr p, void(*visit)(TreeNodePtr node)) {
	if (p != NULL) {
		inorderWalk(p->leftNode, *visit);
		(*visit)(p);
		inorderWalk(p->rightNode, *visit);
	}
}

TreeNodePtr BinarySearchTree::search(int num) {

	TreeNodePtr current = root;

	while (current != NULL)
	{
		if (current->value == num) {
			return current;
		}
		else {
			if (current->value > num)
				current = current->leftNode;
			else
				current = current->rightNode;
		}
	}

	return NULL;
}