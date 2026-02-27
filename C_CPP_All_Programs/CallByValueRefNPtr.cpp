//- A reference is a variable that acts as an alias to another variable,
//  allowing us to access and manipulate the original variable's data directly.
//- It is declared using the '&' symbol and is often used for function 
//  parameters to avoid unnecessary copying of data.
//- References are commonly used for creating more readable and efficient code.

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
	// Call By Value
	cout << "Call By Value Number :" << endl;
	cout << "Before :" << number << endl;  //50
	Increment(number);
	cout << "After :" << number << endl;   //50

	// Call By Reference
	cout << "Call By Value Reference :" << endl;
	cout << "Before :" << number << endl;  //50
	Decrement(number);
	cout << "After :" << number << endl;   //40

	// Call By Address
	cout << "Call By Address :" << endl;
	cout << "Before :" << number << endl;  //40
	PtrIncrement(&number);
	cout << "After :" << number << endl;   //50

	return 0;
}