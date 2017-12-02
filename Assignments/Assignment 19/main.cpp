#include "stdafx.h"
#include <iostream>
#include "Tree.h"

using namespace std;

void display(Tree &);
void menu(Tree &, int &);
void add_child(Tree &, int);

int main()
{
	Tree start;
	int break_int = 0;

	while (break_int != 3)
	{
		menu(start,break_int);
		switch (break_int)
		{
		case 1:
			add_child(start, 1);
			break;
		case 2:
			add_child(start, 2);
			break;
		case 3:	//Exit
			cout << "Goodbye!" << endl;
			break;
		}
	}
    return 0;
}

void display(Tree &temp)
{
	cout << "Number of nodes: "<< temp.treesize() << endl;
	cout << "Depth of tree: " <<  temp.treedepth() << endl;
	cout << "Full tree: "<< (temp.isFull() ? "Yes" : "No") <<endl;
	cout << "Complete tree: "<< (temp.isComplete() ? "Yes" : "No") << endl;
	//3 traversal
	cout << "DisplayInOrder: ";
	temp.displayInOrder();
	cout << endl<< "DisplayPreOrder: ";
	temp.displayPreOrder();
	cout << endl<< "DisplayPostOrder: ";
	temp.displayPostOrder();
}

void menu(Tree &temp, int &u_num)
{
	display(temp);
	int choice = 0;
	while (choice == 0 && choice <= 3)		//not 0 but 1-3 then return
	{
		cout << "1 * Add a left child" << endl;
		cout << "2 * Add a right child" << endl;
		cout << "3 * Exit Program" << endl;
		cout << "Choose from options (1-3): ";
		cin >> choice;
	}
	u_num = choice;
}

void add_child(Tree &temp, int choice)
{
    string user_input;
	cout << "What do you wish to name the node: ";
    cin >> user_input;

	switch (choice)
	{
	case 1:
		temp.insertNode(user_input,choice);		//left
		break;
	case 2:
		temp.insertNode(user_input,choice);		//right
		break;
	}
}
