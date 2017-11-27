#include "stdafx.h"
#include <iostream>

using namespace std;

int  usermenu();
void add_vertices();
void add_edges();
void finds_highest_deg();
void list_iso_vertices();
int  num_loop();
bool is_connected();
bool is_complete();

int main()
{
	int break_int = 0;

	while (break_int != 8)
	{
		break_int = usermenu();
		switch (break_int)
		{
		case 1:
			add_vertices();
			break;
		case 2:
			add_edges();
			break;
		case 3:
			finds_highest_deg();
			break;
		case 4:
			list_iso_vertices();
			break;
		case 5:
			num_loop();
			break;
		case 6:
			is_connected();
			break;
		case 7:
			is_complete();
			break;
		case 8:
			break;
		}


	}
	
	cout << "Goodbye!" << endl;

	return 0;

}

int usermenu()
{
	int input = 0;
	cout << " ~~~~~~~~~~~~~~~ Graph Theory Program Main Menu ~~~~~~~~~~~~~~~ " << endl;
	cout << " 1. - Add a vertices" << endl;
	cout << " 2. - Add a edge" << endl;
	cout << " 3. - Find the highest degree" << endl;
	cout << " 4. - List isolated vertices" << endl;
	cout << " 5. - Find number of loops" << endl;
	cout << " 6. - Is graph connected?" << endl;
	cout << " 7. - Is graph complete?" << endl;
	cout << " 8. - Quit Program" << endl;
	cout << "User Choice (1-8): ";
	cin >> input;
	if (input >= 1 && input <= 8) return input;
	usermenu();
}

void add_vertices()
{

}

void add_edges()
{

}

void finds_highest_deg()
{

}

void list_iso_vertices()
{

}

int  num_loop()
{

}

bool is_connected()
{

}

bool is_complete()
{

}