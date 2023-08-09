#include<iostream>
using namespace std;

int main()
{
	const int constValue = 42;
	int* mutablePtr = const_cast<int*>(&constValue);
	*mutablePtr = 99; // Now it modifies the originally const variable

	int value = 100;
	const int* constPtr = const_cast<const int*>(&value);
	// Now constPtr points to value but treats it as const

	return 0;
}