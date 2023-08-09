// Capture all variables by reference ([&])
// Capture all variables by value ([=])
// Capture by value ([variable])
// Capture by reference ([&variable])

#include<iostream>
using namespace std;

int main()
{
	int a = 10;

	cout << "Before A = " << a << endl;
	auto Fun = [&]()
	{
		a = a + 10;
	};
	Fun();
	cout << "After  A = " << a << endl;

	return 0;
}