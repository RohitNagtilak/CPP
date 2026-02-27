#include <iostream>
using namespace std;

// An inline function suggests to the compiler that it may substitute the
// function's body at each call site (i.e., copy the function code instead of
// performing a call), which can reduce the overhead of function calls for
// small functions. The compiler may still decide whether to actually inline.
inline int Add(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 10;
	int b = 20;
	cout << "Addition is : " << Add(a, b) << endl;

	return 0;
}