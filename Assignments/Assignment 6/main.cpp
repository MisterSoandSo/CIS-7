#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

bool integer_check(int &x)
{
	int temp = x % 2;
	if (temp == 1) return true;		//number is odd
	 return false;					//number is even
}

int main()
{
	string i_input;
	int i;
	bool bool_break = true;
	
	while (bool_break)	//while loop1
	{
		while (true)		//while loop2
		{
			cout << "Please enter an integer value('q' to quit): ";
			getline(cin, i_input);
			if (i_input.empty() || !isdigit(i_input[0]) )
			{
				if(i_input[0] == 'q') bool_break = false;		//break while loop #1
			}
			
			if ((bool_break || isdigit(i_input[0])) && !(i_input.find("."))) break;		//break while loop #2
			
		}
		if (bool_break == false) break;
		
		stringstream convertint(i_input);
		convertint >> i;
		if (integer_check(i))
		{
			cout  << i << " is an odd number." << endl;
		}
		else
		{
			cout  << i << " is an even number." << endl;
		}
		
	}

    return 0;
}
