#include<iostream>
using namespace std;

void Increment(int num)
{
	num = num + 10;
}

void Decrement(int& num)
{
	num = num - 10;
}

void PtrIncrement(int* num)
{
	*num = *num + 10;
}

int main()
{
	int number = 50;

	cout << "Number before increment = " << number << endl; //50
	Increment(number);
	cout << "Number After increment = " << number << endl; //50

	cout << "Number before decrement = " << number << endl; //50
	Decrement(number);
	cout << "Number after decrement = " << number << endl; //40

	cout << "Number before ptrIncrement = " << number << endl; //40
	PtrIncrement(&number);
	cout << "Number after ptrIncrement = " << number << endl; //50

	return 0;
}