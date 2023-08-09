#include<iostream>
using namespace std;

void Print(const string& name = "Rohit")
{
	cout << "Name = " << name<<endl;
}

int main()
{
	Print();
	Print("Bharat");
	return 0;
}