#include<iostream>
using namespace std;

int main()
{
	int value = 42;
	int* intValuePtr = &value;
	char* charValuePtr = reinterpret_cast<char*>(intValuePtr);

	int value1 = 42;
	intptr_t intValueAsIntPtr1 = reinterpret_cast<intptr_t>(&value1);
	int* intValuePtr1 = reinterpret_cast<int*>(intValueAsIntPtr1);

	return 0;
}