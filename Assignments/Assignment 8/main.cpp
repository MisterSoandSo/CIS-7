#include <iostream>
#include <cmath>

/*
Write a program to allow a user to enter a number.
Then let the user guess the number of prime numbers between 0 and that number they entered.
Prove, by exhaustion, whether or not their guess was correct.

*/
using namespace std;

bool prime(int &x, int&y)
{
    int temp_cnt = 0;


    cout << "Primes: ";
    for(int i = 0 ; i<x;i++)
    {
        if(i==2 ||i==3)     ///hardcode values for 2 and 3
        {
            temp_cnt++;
            cout << i << " ";
        }
        for(int j=2; j*j<=i; j++)       ///makes sure to get rid of multiple of 2&3 cases
        {
            if (i % j == 0)
                break;
            else if (j+1 > sqrt(i))
            {
                temp_cnt++;
                cout << i << " ";
            }

        }

    }


    cout << endl;

    if(temp_cnt == y)
    {
        return true;
    }
    else
    {
        y =temp_cnt;
        return false;
    }
}

int main()
{
    int input_num;
    int input_guess;

    cout << "Please input a number: ";
    cin  >> input_num;

    cout << "Guess the number of prime numbers between 0 and " << input_num << ": ";
    cin  >> input_guess;

    if(prime(input_num,input_guess))
    {
        cout << "You are correct! :D" << endl;  ///if correct
    }
    else
    {
        cout << ":( ... The correct number of primes is " << input_guess << endl;  ///if not correct, prime() updates input_guess with correct number
    }

    return 0;
}
