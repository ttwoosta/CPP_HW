
/*
	Binary Search Tree class
	Date: 02/17/2019
	Reference: Data Structure Using C++: D.S. Malik (p. 631)
*/
#pragma once
#include <vector>
#include "TreeNode.h"
using namespace std;

class BinarySearchTree
{
public:
	BinarySearchTree(vector<int> listNum);
	TreeNodePtr root;
	void insert(int insertNum);
	void inorderWalk(void(*visit)(TreeNodePtr node));
	TreeNodePtr search(int num);
private:
	vector<int> _listNum;
	void inorderWalk(TreeNodePtr p, void(*visit)(TreeNodePtr node));
};

typedef BinarySearchTree* BinaryTreePtr;
