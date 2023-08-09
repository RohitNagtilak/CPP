#include<iostream>
using namespace std;

class Shape
{
public:
	void displayShape()
	{
		cout << " This is Shape"<<endl;
	}
};

class Color :public Shape
{
public:
	void displayColor()
	{
		cout << " This is Color" <<endl;
	}
};

class Rectangle: public Color
{
public:
	void displayRectangle()
	{
		cout << " This is Rectangle" << endl;
	}
};

int main()
{
	cout << "\n Multilevel Inheritance" << endl;
	Rectangle rect;
	rect.displayShape();
	rect.displayColor();
	rect.displayRectangle();
	return 0;
}