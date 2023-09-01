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

	return 0;
}