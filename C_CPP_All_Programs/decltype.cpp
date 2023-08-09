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