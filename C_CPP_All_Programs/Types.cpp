#include<iostream>
using namespace std;

class Simple
{
	int x;
public:
	Simple();
	~Simple();
	Simple(int x);
	Simple(Simple&);
};

Simple::Simple() :x{0}
{
	cout << "Default Constructor Called. X = "<< x << endl;
}

Simple::~Simple()
{
	cout << "Destructor Called." << endl;
}

Simple::Simple(int x)
{
	this->x = x;
	cout << "Parameterized Constructor Called. X = "<< x << endl;
}

//Shallow Copy constructor
//
Simple::Simple(Simple &temp)
{
	this->x = temp.x;
	cout << "Copy Constructor Called. x = "<< x << endl;
}

int main()
{
	//Default
	Simple x;

	//Parameterized
	Simple y(10);

	//Copy
	Simple z(x);

	return 0;
}