#pragma once
class TreeNode
{
public:
	int value;

	// constructor
	TreeNode(int num);

	// children node
	TreeNode* leftNode;
	TreeNode* rightNode;
};

typedef TreeNode* TreeNodePtr;