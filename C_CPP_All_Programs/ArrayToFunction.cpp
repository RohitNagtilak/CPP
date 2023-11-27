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

void Display(int(&arr)[3][3], int row, int col)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "  " << arr[i][j];
		}
		cout << endl;
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

	int arr1[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	Display(arr1, 3, 3);
	return 0;
}