#include<iostream>
using namespace std;

class Shape
{
public:
	void displayShape()
	{
		cout << "This is Shape"<<endl;
	}
};

class Color
{
public:
	void displayColor()
	{
		cout << "This is Color"<<endl;
	}
};

class Rectangle : public Shape, public Color
{
public:
	void displayRectangle()
	{
		cout << "This is Rectangle" << endl;
	}
};

int main()
{
	Rectangle rect;
	rect.displayShape();
	rect.displayColor();
	rect.displayRectangle();
	return 0;
}