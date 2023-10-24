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
	
	for (int i=0; i < size; i++)
	{
		cin >> *(arr + i); //cin >> arr[i];
	}
	
	DisplayArray(arr, size);

	cout << endl;
	int a[2][3] = { { 1,2,3},{4,5,6} };
	DisplayArray(&a[0][0], sizeof(a) / sizeof(a[0][0]));

	return 0;
}