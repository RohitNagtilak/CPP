#include<iostream>
using namespace std;

class Shape 
{
public:
	void displayShape()
	{
		cout << "This is Shape" << endl;
	}
};

class Rectangle:public Shape 
{
public:
	void displayRectangle()
	{
		cout << "This is Rectangle" << endl;
	}
};

class Square:public Shape 
{
public:
	void displaySquare()
	{
		cout << "This is Square" << endl;
	}
};

int main() 
{
	cout << "Hierarchical Inheritance" << endl;
	Rectangle rect;
	Square sqr;
	rect.displayRectangle();
	sqr.displaySquare();
	rect.displayShape();
	sqr.displayShape();

	return 0;
}