#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass();
	MyClass(string n);
	~MyClass();

	MyClass operator+(MyClass& x);
	void Display();
private:
	string name;
};

MyClass::MyClass()
{
}

MyClass::MyClass(string n)
{
	name = n;
}

MyClass::~MyClass()
{
}
MyClass MyClass::operator+(MyClass& x)
{
	MyClass c;
	c.name = name + x.name;
	return c;
}

void MyClass::Display()
{
	cout << "Name is = " << name << endl;
}
int main()
{
	MyClass firstName("Hi ");
	firstName.Display();

	MyClass lastName("Hello");
	lastName.Display();
	MyClass fullName;

	fullName = firstName + lastName;
	fullName.Display();
	return 0;
}