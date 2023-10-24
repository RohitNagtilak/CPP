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
	cout << "Before Call By Value Num     = " << number << endl;  //50
	Increment(number);
	cout << "After Call By Value Num      = " << number << endl;  //50

	// Call By Reference
	cout << "Before Call By Reference Num = " << number << endl;  //50
	Decrement(number);
	cout << "After Call By Reference Num  = " << number << endl;  //40

	// Call By Address
	cout << "Before Call By Address Num   = " << number << endl;  //40
	PtrIncrement(&number);
	cout << "After Call By Address Num    = " << number << endl;  //50
	return 0;
}