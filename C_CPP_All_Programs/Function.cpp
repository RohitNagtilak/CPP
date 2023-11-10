#include<iostream>
using namespace std;

class Addition
{
	public:
		int Add(int a, int b)
		{
			cout << "Addition of Integer" << endl;
			return a + b;
		}
		double Add(double a, double b)
		{
			cout << "Addition of Double" << endl;
			return a + b;
		}
		string Add(string a, string b)
		{
			cout << "Addition of String" << endl;
			return a + b;
		}
};

int main()
{
	Addition a;
	cout << " Addition is " << a.Add(5, 3) << endl;
	cout << " Addition is " << a.Add(5.3, 3.4) << endl;
	cout << " Addition is " << a.Add("Rohit ", "Nagtilak");

	return 0;
}