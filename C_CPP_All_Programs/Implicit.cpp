#include<iostream>
using namespace std;

int main()
{
	//Numeric Promotion
	int x=10;
	double y = x;
	long int z = x;

	cout << "y = " << y <<endl;
	cout << "z = " << z << endl;

	//Boolean Conversion
	int num = 10;
	if (num) 
	{
		// num is implicitly converted to a boolean value
		std::cout << "The number is non-zero." << std::endl;
	}

	return 0;
}