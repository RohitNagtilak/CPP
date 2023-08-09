#include<iostream>
using namespace std;
class Shape
{
public:
	void displayShape()
	{
		cout << "This is Shape Class"<<endl;
	}
};

class Rectangle:public virtual Shape
{
public:
	void displayRectangle()
	{
		cout << "This is Rectangle Class"<<endl;
	}
};

class Square:public virtual Shape
{
public:
	void displaySquare()
	{
		cout << "This is Square Class"<<endl;
	}
};

class Hybrid: public Rectangle, public Square
{
public:
	void displayHybrid()
	{
		cout << "This is Hybrid Class"<<endl;
	}
};

int main()
{
	cout << "Hybrid Inheritance and Virtual Class"<<endl;

	Hybrid hbr;
	hbr.displayShape();
	hbr.displayRectangle();
	hbr.displaySquare();
	hbr.displayHybrid();

	return 0;
}