// "-> int" is the trailing return type (C++11 feature),
// but here it's not needed because from C++14 onward the compiler can deduce the return type automatically.

#include<iostream>
using namespace std;

auto add(int a, int b) -> int  //trailing return type syntax
{
	return a + b;
}

int main()
{
	
	auto x = 10;  // x is deduced as int
	auto y = 3.14;  // y is deduced as double
	auto name = "John";  // name is deduced as const char *
	cout << add(x, y);

	return 0;
}