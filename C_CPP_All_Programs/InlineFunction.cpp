#include<iostream>
using namespace std;

int inline Add(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 10;
	int b = 20;
	cout << "Addition is : " << Add(a, b) << endl;

	return 0;
}