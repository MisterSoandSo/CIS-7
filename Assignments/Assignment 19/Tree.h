#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include <string>
using namespace std;

class Tree
{
private:
	struct TreeNode
	{
		string Node_Name;
		TreeNode *left;
		TreeNode *right;
	};

	TreeNode *root;

	void insert(TreeNode *&nodePtr, TreeNode *&newNode) 
	{
		if (nodePtr == NULL)
			nodePtr = newNode;
		else if (newNode->Node_Name == "")
			insert(nodePtr->left, newNode);
		else 
			insert(nodePtr->right, newNode);
	}
	
	void displayInOrder(TreeNode *nodePtr) const
	{
		if (nodePtr)
		{
			displayInOrder(nodePtr->left);
			cout << nodePtr->Node_Name << endl;
			displayInOrder(nodePtr->right);
		}
	}
	void displayPreOrder(TreeNode *nodePtr) const
	{
		if (nodePtr)
		{
			cout << nodePtr->Node_Name << endl;
			displayPreOrder(nodePtr->left);
			displayPreOrder(nodePtr->right);
		}
	}
	void displayPostOrder(TreeNode *nodePtr) const
	{
		if (nodePtr)
		{
			displayPostOrder(nodePtr->left);
			displayPostOrder(nodePtr->right);
			cout << nodePtr->Node_Name << endl;
		}
	}

public:
	Tree()
	{
		root = NULL;
	}
	
	void insertNode(string)
	{

	}
	
	
	void displayInOrder() const
	{
		displayInOrder(root);
	}
	void displayPreOrder() const
	{
		displayPreOrder(root);
	}
	void displayPostOrder() const
	{
		displayPostOrder(root);
	}
};

#endif