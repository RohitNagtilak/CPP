//An array is a collection of elements of the same data type stored in contiguous memory locations. 
//It is a fundamental data structure that allows you to store and manipulate a fixed number of elements.
#include<iostream>
using namespace std;

void DisplayArray(int* arr, int size)
{
	cout << "Array elements are :" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << " " << *(arr + i) << endl; //cout << " " << arr[i] << endl; 
	}
}

int main()
{
	int size;
	cout << "Enter Number of element : ";
	cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		cin >> *(arr + i); //cin >> arr[i];
	}
	DisplayArray(arr, size);
	//or DisplayArray(arr, size);
	delete[] arr;

	return 0;
}