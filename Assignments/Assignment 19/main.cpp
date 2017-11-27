#include "stdafx.h"
#include "Tree.h"

int menu(int &temp)
{
	temp = 0;
	while (temp == 0 && temp <= 4)		//not 0 but 1-4 then return
	{
		cout << "1 * Add a new node" << endl;
		cout << "2 * Add a left child" << endl;
		cout << "3 * Add a right child" << endl;
		cout << "4 * Exit Program" << endl;
		cout << "Choose from options (1-4): ";
		cin >> temp;
	}
	return temp;
}

void display()
{

}

int main()
{
	Tree start();
	int break_int = 0;

	while (break_int != 4)
	{
		menu(break_int);
		switch (break_int)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:	//Exit
			cout << "Goodbye!" << endl;
			break;
		}
	}
    return 0;
}

