/*Write a program to print the prime factorization of a given input number*/

#include <iostream>
#include <string>
#include <cmath>
#include <locale>
#include <sstream>

using namespace std;

int primefactor(int &x)
{
    while(x%2==0)   ///try dividing by 2
    {
        cout << "2 * ";
        x=x/2;
    }
    while(x%3==0)   ///try dividing by 3
    {
        cout << "3 * ";
        x=x/3;
    }

    if(x>2)
        cout << x;

}

bool integer_check(string &input)
{
    cout << "checking int ..." <<endl;
	if (input.empty() || !isdigit(input[0]))
	{
	    cout<<"Not valid!"<<endl;
		 return false;		//not integer
	}

	if ((isdigit(input[0])) && !(input.find(".")))
	{
	  cout<<"Valid!"<<endl;
	    return true;		//integer
	}
}

int main()
{
    string input;
    int i;

    bool bool_intcheck = true;

	while (true)
	{
		cout<<"Enter a valid integer to get prime factorization: ";
		getline(cin, input);

		bool_intcheck = integer_check(input);
		if (bool_intcheck)
		{
		    cout << "Converting to int" <<endl;
			stringstream convert_int(input);
			convert_int >> i;
			cout<<"Prime factorization of " << input <<" is "<< primefactor(i)<<endl;
		}
		cout<< "Finished" <<endl;

	}
    return 0;
}
