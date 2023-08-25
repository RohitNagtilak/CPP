#include<iostream>
using namespace std;

int main()
{
	int intValue = 65;
	char* charPointer = reinterpret_cast<char*>(&intValue);

	cout << charPointer;
	return 0;
}

//reinterpret_cast is a casting operator used to convert one pointer type to another,
//even if they are unrelated.
//It's often used for low-level bit manipulation or to treat memory as a different type. 
//However, it should be used with caution due to potential undefined behavior.