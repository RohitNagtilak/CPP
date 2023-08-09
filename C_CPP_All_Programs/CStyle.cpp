//Explicit Casting
#include<iostream>
using namespace std;

int main()
{
	int intValue = 10;
	double doubleValue = (double)intValue;
	// C-style cast to convert int to double


	int num = 42;
	void* ptr = (void*)&num;
	// C-style cast to convert int* to void*

	return 0;
}