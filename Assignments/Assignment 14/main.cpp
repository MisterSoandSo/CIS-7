#include <iostream>
#include <stack>

using namespace std;

void initialization(int, stack <int> &);
void reorderstack(stack <int> &);
int factorial(stack <int> &);
int fibonacci(int);
void c_pause();
void displaystack(stack<int>);

int main()
{
	char input = ' ';
	int number = 0,output = 0;
	stack<int> input_stack;

	while (input != 'a' && input != 'b')
	{
		cout << "Choose factorial(a) or Fibonacci(b): ";
		cin >> input;
		if ((input != 'a' && input != 'b')) cout << "Invalid Input!" << endl;
	}
	while (number < 1)
	{
		cout << "Please input a positive number greater than 1: ";
		cin >> number;
		if (number < 1) cout << "Invalid Input!" << endl;
	}

	initialization(number, input_stack);

	if (input == 'a')
	{
		reorderstack(input_stack);
		output = factorial(input_stack);
		cout << "The factorial value of " << number << " is " << output << endl;
	}
	else
	{
		output = fibonacci(input_stack.size());
		cout << "The fibonoacci value of " << number << " is " << output << endl;
	}
	c_pause();

	return 0;
}


void initialization(int num, stack <int> &temp)		//recursive initialization
{
	if (num == 0) return;
	else
	{
		temp.push(num);
		initialization(num - 1, temp);
	}
}

void reorderstack(stack <int> &origin)
{
	stack<int> temp;
	int temp_sz = origin.size();
	for (int i = 0; i < temp_sz;i++)
	{
		temp.push(origin.top());
		origin.pop();
	}
	origin = temp;
}

int factorial(stack <int> & stack)
{
	if (stack.empty()) return 1;
	displaystack(stack);
	int temp_int = stack.top();
	stack.pop();
	return temp_int*factorial(stack);
}

int fibonacci(int stack_sz)
{
	if (stack_sz == 0)	return 0;
	if (stack_sz == 1)	return 1;
	return fibonacci(stack_sz - 1) + fibonacci(stack_sz - 2);
}

void c_pause()
{
	cin.ignore();
	cin.get();
}

void displaystack(stack<int> stack)
{
	int dispsz = stack.size();
	cout << "Stack Content: ";
	for (int i = 0; i < dispsz; i++)
	{
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
}
