#include<iostream>
using namespace std;
int main()
{
	int n, i;
	int* ptr = NULL;
	cout << "\n Enter Size :";
	cin >> n;
	try
	{
		if (n <= 0)
			throw "\n Exception: Bad Memory Allocation..!\n";

		ptr = new int[n];
		cout << "\n Enter values";
		for (i = 0; i < n; i++)
			cin >> ptr[i];
		cout << "\n Values Are :\n";
		for (i = 0; i < n; i++)
			cout << " " << ptr[i];

		delete[] ptr;
	}
	catch (const char* str)
	{
		cout << " " << str;
		if (ptr)
			delete[]ptr;
	}
	return 0;
}