#include<iostream>
using namespace std;

auto add(int a, int b) -> int
{
	return a + b;
}

int main()
{
	auto x = 10;  // x is deduced as int
	auto y = 3.14;  // y is deduced as double
	auto name = "John";  // name is deduced as const char
	cout << add(x, y);
	return 0;
}