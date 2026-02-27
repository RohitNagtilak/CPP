#include<iostream>
using namespace std;

// Simple demonstration of function pointers in C++:
// - `Add` and `Sub` are functions that match the signature `int(int,int)`
// - `fptr` is a pointer to such functions and is used to call them dynamically
// - `Disp` returns a string and `Display` accepts a function pointer with signature `string()`
//   to demonstrate function pointers for different signatures.

int Add(int a, int b)
{
	// Returns the sum of two integers
	return a + b;
}

int Sub(int a, int b)
{
	// Returns the result of subtracting b from a
	return a - b;
}

// Display accepts a function pointer to a function that takes no arguments and returns a string.
// The parameter type is: string (*fptr)()
void Display(string(*fptr)())
{
	// Call the passed-in function via the pointer and print its returned string
	cout << fptr() << endl;
}

string Disp()
{
	// A simple function that returns a name (used with Display)
	return "Rohit";
}

int main()
{
	// Declare a function pointer `fptr` that can point to functions taking two ints and returning int
	int (*fptr)(int, int);

	// Point to `Add` and call via the pointer
	fptr = Add;
	cout << "Addition is : " << fptr(10, 20) << endl;

	// Reassign the pointer to `Sub` and call again
	fptr = Sub;
	cout << "Substraction is : " << fptr(20, 10) << endl;

	// Declare and initialize a function pointer for functions returning string (no params)
	string(*fptr1)();
	fptr1 = Disp;
	// Pass the pointer to Display to call it indirectly
	Display(fptr1);

	return 0;
}