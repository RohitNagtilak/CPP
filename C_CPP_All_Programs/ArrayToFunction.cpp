#include<iostream>
using namespace std;

void DisplayArray(int* arr, int size)
{
	cout << "Array elements are :" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << " " << *(arr + i) << endl;
	}
}

int main()
{
	int size;
	cout << "Enter Number of element :";
	cin >> size;

	int* arr = new int[size];
	
	for (int i=0; i < size; i++)
	{
		cin >> *(arr + i);
	}
	
	DisplayArray(arr, size);

	return 0;
}