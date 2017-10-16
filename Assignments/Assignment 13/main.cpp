#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

struct Tower
{
	char name;
	stack<int>disks;
	bool empty_pole;
	int stack_sz;
} pole_Beg, pole_Alt, pole_End;
int count_glb = 0;

void initialize_pole(int x, Tower &pole, char name, int size_sz)    ///construct initial stack
{
	pole.name = name;
	if (x == 0)
	{
		pole.empty_pole = true;
	}
	for (int i = x; i>0;i--)
	{
		pole.disks.push(i);
		pole.empty_pole = false;
	}
	pole.stack_sz = size_sz;
}

void print_pole(Tower pole)   ///print out a poles
{
	int num_disk = pole.disks.size();
	int stack_sz = pole.stack_sz;
	if ( num_disk < stack_sz)
	{
		for (int i = 0; i<stack_sz - num_disk;i++) { cout << "- "; }

	}
	while (!pole.disks.empty())
	{
		cout << pole.disks.top() << " ";
		pole.disks.pop();
	}
}

void display_all_poles(const Tower x, const Tower y, const Tower z)      ///print out all poles
{
	if (x.name == 'A')
	{
		cout << "\nTower " << x.name << ": "; print_pole(x);
	}
	else if (y.name == 'A')
	{
		cout << "\nTower " << y.name << ": "; print_pole(y);
	}
	else
	{
		cout << "\nTower " << z.name << ": "; print_pole(z);
	}

	if (x.name == 'B')
	{
		cout << "\nTower " << x.name << ": "; print_pole(x);
	}
	else if (y.name == 'B')
	{
		cout << "\nTower " << y.name << ": "; print_pole(y);
	}
	else
	{
		cout << "\nTower " << z.name << ": "; print_pole(z);
	}

	if (x.name == 'C')
	{
		cout << "\nTower " << x.name << ": "; print_pole(x);
	}
	else if (y.name == 'C')
	{
		cout << "\nTower " << y.name << ": "; print_pole(y);
	}
	else
	{
		cout << "\nTower " << z.name << ": "; print_pole(z);
	}

	cout << endl << endl;
}

void move_poles(Tower  &first, Tower  &second)
{

	int temp = first.disks.top();

	first.disks.pop();
	second.disks.push(temp);

	cout << "Move # " << count_glb+1 << ": " << temp << " is moved from Tower " << first.name << " to Tower " << second.name << ".";
	count_glb++;
}
void custom_pause()
{
	cin.ignore();
	cin.get();
}

void hanoi_rec(int num, Tower &x, Tower &y, Tower &z)
{
	if (num == 1)
	{
		move_poles(x, z);
		display_all_poles(x, y, z);
		custom_pause();
	}
	else
	{
		hanoi_rec(num - 1, x, z, y);

		move_poles(x, z);
		display_all_poles(x, y, z);
		custom_pause();

		hanoi_rec(num - 1, y, x, z);
	}


}

int main()
{
	int number_disks;
	cout << "Tower of Hanoi -  Please enter an integer for number of disks: ";
	cin >> number_disks;

	initialize_pole(number_disks, pole_Beg, 'A', number_disks);
	initialize_pole(0, pole_Alt, 'B', number_disks);
	initialize_pole(0, pole_End, 'C', number_disks);
	hanoi_rec(number_disks, pole_Beg, pole_Alt, pole_End);

	if (pole_End.disks.size() == number_disks)
	{
		cout << "Congrats, you finished the puzzle in " << count_glb << " moves." << endl;
	}
	else
	{
		cout << "Program Finished but number of disk dont match stach size." << endl;
	}
	custom_pause();
	return 0;
}

