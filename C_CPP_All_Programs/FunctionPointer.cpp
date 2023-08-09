#include<iostream>
using namespace std;

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

void Display(string(*fptr)())
{
	cout << fptr() << endl;
}

string Disp()
{
	return "Rohit";
}

int main()
{
	int (*fptr)(int, int);
	fptr = Add;
	cout << "Addition is : " << fptr(10, 20) << endl;

	fptr = Sub;
	cout << "Substraction is : " << fptr(20, 10) << endl;

	string(*fptr1)() = Disp;

	Display(fptr1);

	return 0;
}