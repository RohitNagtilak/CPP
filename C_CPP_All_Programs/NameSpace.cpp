#include<iostream>
using namespace std;
namespace s1 
{
	int num = 100;
	void display()
	{
		cout << "\n namespace s1";
	}
}
namespace s2 
{
	void display()
	{
		cout << "\n namespace s2";
	}
}

int main()
{
	cout << "\n num =" << s1::num;
	s1::display();
	return 0;
}