#include <iostream>
using namespace std;
class Parent
{
public:
	Parent()
	{
		cout << "Parent Constructor Called" << endl;
	}
	virtual ~Parent() //if we don't make virtual then child destructor will not called.
	{
		cout << "Parent Destructor Called." << endl;
	}
};

class Child :public Parent
{
public:
	Child()
	{
		cout << "Child Constructor Called." << endl;
	}
	~Child()
	{
		cout << "Child Destructor Called." << endl;
	}
};

int main()
{
	Parent* p = new Child();
	delete p;
	return 0;
}