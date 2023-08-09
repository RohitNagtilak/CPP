#include<iostream>
using namespace std;
class Parent
{
public:
	virtual void Display()
	{
		cout << "Parent Called." << endl;
	}
};

class Child : public Parent
{
public:
	void Display() override
	{
		cout << "Child Called." << endl;
	}
};

int main()
{
	Parent p;
	p.Display();

	Child c;
	c.Display();

	Parent* p1 = new Child();
	p1->Display();

	delete p1;
	return 0;
}