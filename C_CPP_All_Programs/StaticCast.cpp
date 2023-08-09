//Explicit Casting
#include<iostream>
using namespace std;

int main()
{
	//Numeric Conversions:
	int intValue = 42;
	double doubleValue = static_cast<double>(intValue);
	
	//Explicit Type Conversions
	int intValue1 = 42;
	void* voidPtr = static_cast<void*>(&intValue1);

	return 0;
}

/* 
When to Use static_cast:
------------------------
Use static_cast when you want to perform safe and well - defined conversions between numeric types,
pointers within an inheritance hierarchy, and explicit type conversions.
Use it when you want the compiler to catch potential type conversion issues at compile - time.

When to Avoid static_cast :
---------------------------
Avoid static_cast when dealing with pointers in a polymorphic hierarchy.For these cases, 
use dynamic_cast for runtime type checking and handling.
Avoid using static_cast when dealing with const and volatile conversions.For these cases, 
use const_cast if you need to add or remove constness and volatility explicitly.
*/