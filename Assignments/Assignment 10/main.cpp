/*Write a program to print the prime factorization of a given input number*/

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

void primefactor(int &x)        ///find prime factors
{
    while(x%2==0)   ///try dividing by 2
    {
        cout << "2 ";
        if(x/2 != 1) cout << "* ";      ///resolve lingering *
        x=x/2;
    }
    while(x%3==0)   ///try dividing by 3
    {
        cout << "3 ";
           if(x/3 != 1) cout << "* ";      ///resolve lingering *
        x=x/3;
    }

    if(x>2)
        cout << x;

}

bool integer_check(string &input)       /// check if string is a valid integer
{
    
	if (input == "q" || input.empty() || !isdigit(input[0]))
	{
	    return false;		//not integer
	}

	if ((isdigit(input[0])) && !(input.find(".")))
	{
        return true;		//integer
	}
}

int main()
{
    string input;
    int i;

	while (true)
	{
		cout<<"Enter a valid number to get prime factorization('q' to quit): ";
		getline(cin, input);
	
		if (integer_check(input))
		{
			stringstream convert_int(input);
			convert_int >> i;
			if(i !=1)
			{
			    cout << "Prime factorization of " << input <<" is ";
		    	primefactor(i);
			    cout << endl;
			}
			else
			{
			    cout <<"Error: '1' has no prime factors and is neither prime nor composite."<<endl;   
			}
		}
		if (input == "q") break;    ///break out of loop

	}
    return 0;
}
