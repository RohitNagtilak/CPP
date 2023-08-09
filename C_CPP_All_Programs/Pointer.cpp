#include<iostream>
using namespace std;
int main()
{
	int* a;
	int** c;

	int b = 20;

	a = &b;
	c = &a;

	cout << "*a = " << *a << endl;
	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;

	cout << "b = " << b << endl;
	cout << "&b = " << &b << endl;

	cout << "c = " << c << endl;
	cout << "*c = " << *c << endl;
	cout << "**c = " << **c << endl;

	return 0;
}