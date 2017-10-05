/*
Write a program that asks the user for 2 positive integers,
validates the input, and then prints out the GCD of those integers.

Brute Force it!  and euclidean method
print out which as faster
*/

#include <iostream>
#include <ctime>

using namespace std;

int brute_force(int x, int y)
{
    int temp;
    if (y == 0) return x;
    for(int i = 1; i <= x; i++)
    {
        if((x%i==0) && (y%i==0))   temp = i;
    }
    return temp;
}

int euclidean_method(int x, int y)
{
    if (y == 0) return x;
    if (y > x) swap(x, y);
    return euclidean_method(y, x % y);

}

int main()
{
    int a,b;
    clock_t b_clock;
    clock_t e_clock;

    cout  << "Input 2 Positive integers(x enter y) " << endl << "First Positive Integer: ";
    cin   >> a;
    while(!cin.good())
    {
        cout<<"Invalid input! Please input a positive integer: ";
        cin.clear();
        cin.ignore(10000,'\n');
        cin >> a;
    }


    cout  << "Second Positive Integer: ";
    cin   >> b;
    while(!cin.good())
    {
        cout<<"Invalid input! Please input a positive integer: ";
        cin.clear();
        cin.ignore(10000,'\n');
        cin >> b;
    }

    b_clock = clock();
    cout << "GCD Brute Force: " << brute_force(a,b) << endl;
    double b_clock_final = (clock() - b_clock)/(double) CLOCKS_PER_SEC;
    cout << "The time it took was " << b_clock << " seconds" <<endl;

    e_clock = clock();
    cout << "GCD Euclidean Method: " << euclidean_method(a,b) << endl;
    double e_clock_final = (clock() - e_clock)/(double) CLOCKS_PER_SEC;
    cout << "The time it took was " << e_clock << " seconds" <<endl;

    if(b_clock_final < e_clock_final)
    {
        cout<< "Brute Force was faster"<<endl;
    }
    if(b_clock_final > e_clock_final)
    {
        cout<< "Euclidean was faster"<<endl;
    }
    if(b_clock_final == e_clock_final)
    {
        cout<< "Both methods finished at the same time."<<endl;
    }

    return 0;
}
