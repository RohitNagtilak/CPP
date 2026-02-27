#include<iostream>
using namespace std;

class Addition
{
public:
	int Add(int a, int b)
	{
		cout << "Addition of Integer : ";
		return a + b;
	}
	double Add(double a, double b)
	{
		cout << "Addition of Double  : ";
		return a + b;
	}
	string Add(string a, string b)
	{
		cout << "Addition of String  : ";
		return a + b;
	}
};

int main()
{
	Addition obj;
	cout << obj.Add(5, 3) << endl;
	cout << obj.Add(5.3, 3.4) << endl;
	cout << obj.Add("Rohit ", "Nagtilak") << endl;

	return 0;
}