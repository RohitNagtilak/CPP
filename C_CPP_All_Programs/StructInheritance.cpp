#include<iostream>
using namespace std;
struct  Shape
{
	void displayShape()
	{
		cout << "This is Shape Struct" << endl;
	}
};
struct Rectangle:Shape
{
	void displayRectangle()
	{
		cout << "This is Rectangle Struct" << endl;
	}
};
int main()
{
	Rectangle rect;
	rect.displayShape();
	rect.displayRectangle();
	return 0;
}