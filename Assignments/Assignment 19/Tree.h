#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include <string>
using namespace std;

class Tree
{
	//public:
		//class TreeNode;
	private:
		class TreeNode
		{
			private:
				string Node_Name;
				TreeNode *left;
				TreeNode *right;
			public:
				string passNode_Name()
				{
					return Node_Name;
				}
				TreeNode *passleft()
				{
					return left;
				}
				TreeNode *passright()
				{
					return right;
				}
				void setNode_Name(string input)
				{
					Node_Name = input;
				}
				void setleft(TreeNode *left_in)
				{
					left = left_in;
				}
				void setright(TreeNode *right_in)
				{
					right = right_in;
				}
				void insert(TreeNode *&nodePtr, TreeNode *&newNode, string left_or_right)
				{
					if (nodePtr == NULL)
					{
						nodePtr = newNode;
					}
					if (left_or_right == "left")
					{
						insert(nodePtr->left, newNode, "choosen");
					}
					if (left_or_right == "right")
					{
						insert(nodePtr->right, newNode, "choosen");
					}

				}
				void displayTreeInOrder(TreeNode *nodePtr) const
				{
					if (nodePtr)
					{
						displayTreeInOrder(nodePtr->left);
						cout << nodePtr->Node_Name << endl;
						displayTreeInOrder(nodePtr->right);
					}
				}
				void displayTreePreOrder(TreeNode *nodePtr) const
				{
					if (nodePtr)
					{
						cout << nodePtr->Node_Name << endl;
						displayTreePreOrder(nodePtr->left);
						displayTreePreOrder(nodePtr->right);
					}
				}
				void displayTreePostOrder(TreeNode *nodePtr) const
				{
					if (nodePtr)
					{
						displayTreePostOrder(nodePtr->left);
						displayTreePostOrder(nodePtr->right);
						cout << nodePtr->Node_Name << endl;
					}
				}
		};
		int TreeSize;
		TreeNode *root;

	public:
		Tree()      //initializing Root
		{
			root->setNode_Name("Tree Root");
			root->setleft(NULL);
			root->setright(NULL);
			TreeSize = 0;
		}

		~Tree()
		{
			delete root;
		}

		void insertNode(string input, int choice)
		{
			TreeNode *newNode;
			TreeNode *destination;
			string user_node;
			bool done = false;

			newNode = new TreeNode;
			
			newNode->setNode_Name(input);
			newNode->setleft(NULL);
			newNode->setright(NULL);
			while (!done)
			{
				cout << "Which node do you wish to put it after?: ";
				cin >> user_node;
				destination = traversal(user_node, root);

				if (choice == 1)
				{
					if (destination->passleft() == NULL)
					{
						root->insert(destination, newNode, "left");	//assume left
						done = true;
					}
					else
					{
						cout << "The left child of Node " << destination->passNode_Name() << "is not empty.\nInvalid action Please use a valid node!" << endl;

					}

				}
				if (choice == 2)
				{
					if (destination->passright() == NULL)
					{
						root->insert(destination, newNode, "right");	//assume right
						done = true;
					}
					else
					{
						cout << "The right child of Node " << destination->passNode_Name() << "is not empty.\nInvalid action Please use a valid node!" << endl;
					}

				}
			}


		}

		TreeNode *traversal(const string & name, TreeNode * base) const
		{
			TreeNode * temp;

			if (base == NULL)
			{
				return NULL;
			}
			string check1 = base->passNode_Name();
			if ( check1 == name)
			{
				return base;
			}

			temp = traversal(name, base->passleft());

			if (temp)
			{
				return temp;
			}

			return traversal(name, base->passright());
		}

		int traverseForDepth(TreeNode *base, int currentDepth) const
		{
			int maxDepth = 0;

			if (base)
			{
				maxDepth = currentDepth;

				traverseForDepth(base->passleft(), currentDepth + 1);
				traverseForDepth(base->passright(), currentDepth + 1);
			}

			return maxDepth;
		}

		bool traverseForComplete(TreeNode * base, int index) const
		{
			   if (base == NULL)
			{
				return true;
			}

			if (index >= TreeSize)
			{
				return false;
			}

			return (traverseForComplete(base->passleft(), 2 * index + 1) &&
					traverseForComplete(base->passright(), 2 * index + 2));
		}

		int treesize()
		{
			return TreeSize;
		}

		int treedepth()
		{
			return traverseForDepth(root,0);
		}

		bool isFull()
		{
			return ((1 << (treedepth() + 1)) - 1 == TreeSize);
		}

		bool isComplete()
		{
			return traverseForComplete(root, 0);
		}

		void displayInOrder() const
		{
			root->displayTreeInOrder(root);
		}

		void displayPreOrder() const
		{
			root->displayTreePreOrder(root);
		}

		void displayPostOrder() const
		{
			root->displayTreePostOrder(root);
		}

};

#endif
