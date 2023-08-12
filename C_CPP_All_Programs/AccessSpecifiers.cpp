#include<iostream>
using namespace std;
class Parent
{
	int i = 10;
protected:
	int j = 20;
public:
	int k = 30;
};

class Child : public Parent //Default access specifier is Private
{
	//Protected members can be accessible in child class
	int x = j;

	// Private members can not be accessible outside class
	//int y = i;
};

int main()
{
	// Private and Protected members are not accessible outside the class.
	// i.e. i, j (private is default access specifier in cpp)
	Parent p;
	cout << " K from parent is " << p.k << endl;

	Child c;
	c.k;
	cout << " K from child is " << c.k << endl;

	return 0;
}