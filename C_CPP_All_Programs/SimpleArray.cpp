#include<iostream>
using namespace std;
int main()
{

	int num;
	cout << "Enter No Of Element:" << endl;
	cin >> num;

	int *arr = new int[num];
	cout << "Enter " << num << " Elements : " << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> *(arr + i);
	}

	cout << "Entered Elements are :"<<endl;
	for (int i = 0; i < num; i++)
	{
		cout<<" "<< * (arr + i)<<endl;
	}

	int arr1[2];
	cout << "Enter " << 2 << " Elements : " << endl;
	for (int i = 0; i < 2; i++)
	{
		cin >> arr1[i];
	}
	cout << "Entered Elements are :" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << " " << arr1[i]<< endl;
	}
	
	return 0;
}