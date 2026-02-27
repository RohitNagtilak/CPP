//`auto` tells the compiler to deduce the type from the initializer or return value; simple and convenient, but may drop references or `const`.
//`decltype` gives the exact type of an expression without evaluating it, preserving references and `const`.
//Use `auto` for easy type deduction; use `decltype` when you need the precise type, especially in templates or complex expressions.

#include<iostream>
using namespace std;

template<typename T, typename U>
auto multiply(T a, U b) -> decltype(a * b)
{
	return a * b;
}

int main()
{
	int x = 10;
	double y = 3.14;
	decltype(x) result1;  // result1 is deduced as int
	decltype(y) result2;  // result2 is deduced as double

	cout << multiply(x, y);
	return 0;
}