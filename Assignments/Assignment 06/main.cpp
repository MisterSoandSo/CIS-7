#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

bool mod_check(int &x)
{
	int temp = x % 2;
	if (temp == 1) return true;		//number is odd
	 return false;					//number is even
}

bool integer_check(string &input)
{
	if (input.empty() || !isdigit(input[0]))
	{
		 return false;		//not integer
	}

	if ((isdigit(input[0])) && !(input.find("."))) return true;		//integer
}

int main()
{
	string i_input;
	int i;
	bool bool_break = true;

	while (true)
	{
		cout << "Please enter an integer value('q' to quit): ";
		getline(cin, i_input);
		if (integer_check(i_input))
		{
			stringstream convert_int(i_input);
			convert_int >> i;
			if (mod_check(i))
			{
				cout << i << " is an odd number." << endl;
			}
			else
			{
				cout << i << " is an even number." << endl;
			}
		}
		if (!integer_check(i_input) && (i_input == "q"))
		{
			break;		//exit
		}


	}

    return 0;
}

