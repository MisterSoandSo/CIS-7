#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;

int usermenu();
void add_2_set(set<string>&);
void inter_set(set<string>, set<string>);
void union_set(set<string>, set<string>);
void diffe_set(set<string>, set<string>, bool);
void cross_set(set<string>, set<string>);
void power_set(set<string>);
void display_set(set<string>);

int main()
{
	set<string>A_SET = {"1","2","3","4","5","6"};		//empty string sets
	set<string>B_SET = { "2","5","6","7"};		//empty string sets
	int break_int = 0;

	while (break_int != 11)
	{
		break_int = usermenu();
		switch (break_int)
		{
			case 1:
				add_2_set(A_SET);
				break;
			case 2:
				add_2_set(B_SET);
				break;
			case 3:
				inter_set(A_SET,B_SET);
				break;
			case 4:
				union_set(A_SET, B_SET);
				break;
			case 5:
				diffe_set(A_SET, B_SET,true);
				break;
			case 6:
				diffe_set(B_SET, A_SET,true);
				break;
			case 7:
				cross_set(A_SET, B_SET);
				break;
			case 8:
				cross_set(B_SET, A_SET);
				break;
			case 9:
				power_set(A_SET);
				break;
			case 10:
				power_set(B_SET);
				break;
			case 11:
				break;
		}
	}
	cout << "Goodbye!" << endl;
	return 0;
}

int usermenu()
{
	int input = 0;
	cout << " ~~~~~~~~~~~~~~~ Set Theory Program Main Menu ~~~~~~~~~~~~~~~ " << endl;
	cout <<	" 1. - Add a value to A : Allow the user to add a string value to A" << endl;
	cout << " 2. - Add a value to B : Allow the user to add a string value to B" << endl;
	cout << " 3. - A interset B : Prints out the contents of A interset B" << endl;
	cout << " 4. - A union B : Prints out the contents of A union B" << endl;
	cout << " 5. - A diff B : Prints out the contents of A - B" << endl;
	cout << " 6. - B diff A : Prints out the contents of B - A" << endl;
	cout << " 7. - A X B" << endl;
	cout << " 8. - B X A" << endl;
	cout << " 9. - Powersets : Prints out the powersets of A" << endl;
	cout << "10. - Powersets : Prints out the powersets of B" << endl;
	cout << "11. - Quit Program" << endl;
	cout << "User Choice (1-11): ";
	cin >> input;
	if (input >= 1 && input <= 11) return input;
	usermenu();
}	

void add_2_set(set<string>&temp)
{
	string s_input;
	cout << "Add value to set: ";
	cin  >> s_input;
	temp.insert(s_input);
}

void inter_set(set<string>A, set<string>B)///what they both have
{
	string temp_str = " ";
	set<string>::iterator it_A;
	set<string>::iterator it_B;

	for (it_A = A.begin(); it_A != A.end(); ++it_A)
	{
		for (it_B = B.begin(); it_B != B.end(); ++it_B)
		{
			if (*it_A == *it_B)
			{
				temp_str += " " + *it_A;
			}
		}
	}
	if (temp_str == " ") temp_str = "No Sets are Intersecting";
	cout << "The intersecting set elements are: " << temp_str << endl;
}

void union_set(set<string>A, set<string>B)	///print both sets without repeats
{
	string temp_str = "";
	set<string>::iterator it_A;
	set<string>::iterator it_B;

	cout << "The union set elements are: ";

	for (it_A = A.begin(); it_A != A.end(); ++it_A)
	{
		cout << *it_A << " ";
	}

	diffe_set(B, A,false);
	
	cout<< endl;
}

void diffe_set(set<string>A, set<string>B, bool dis_logic)	///opposite if intersecting but only display one set
{
	string temp_str = "";
	set<string>::iterator it_A;
	set<string>::iterator it_B;
	set<string> temp = A;
	for (it_A = A.begin(); it_A != A.end(); ++it_A)
	{
		for (it_B = B.begin(); it_B != B.end(); ++it_B)
		{
			if (*it_A == *it_B)
			{
				temp.erase(*it_A);
			}
		}
	}
	if(dis_logic == true)
	{
		cout << "The difference in the set is :";
		if (temp.empty()) cout << "There are differences between the 2 sets." << endl;
	}
	display_set(temp);
}

void cross_set(set<string>A, set<string>B)
{
	string temp_str = "";
	set<string>::iterator it_A;
	set<string>::iterator it_B;
	cout << "The Cross Product of the Sets:" << endl;

	for (it_A = A.begin(); it_A != A.end(); ++it_A)
	{
		for (it_B = B.begin(); it_B != B.end(); ++it_B)
		{
			cout << "(" << *it_A << "," << *it_B << ") ";
		}
		cout << endl;
	}
}

void power_set(set<string>temp)
{
	set<string>::iterator it;
	cout << "The Power Set: "<<endl;

	for (int i = 0;i < temp.size();i++)
	{
		if (i = 0) cout << "{ }";
		for (it = temp.begin(); it != temp.end(); it++)
		{

		}
		cout << endl;
	}

}


void display_set(set<string>temp)
{
	set<string>::iterator it;
	for (it = temp.begin(); it != temp.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}