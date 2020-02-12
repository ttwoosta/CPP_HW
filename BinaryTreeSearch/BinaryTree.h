
/*
	Binary class
*/
#pragma once
#include <vector>
#include "TreeNode.h"
using namespace std;

class BinaryTree
{
public:
	BinaryTree(vector<int> listNum);
	TreeNodePtr root;
	virtual void printDebug();

private:
	vector<int> _listNum;
};

typedef BinaryTree* BinaryTreePtr;
