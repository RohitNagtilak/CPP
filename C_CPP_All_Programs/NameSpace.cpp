#include<iostream>
// Header vs namespace: `#include <iostream>` brings declarations (like `std::cout`) from the standard library header;
// the `std` namespace is the scope that contains those names, and `using namespace std;` lets you use them unqualified.
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