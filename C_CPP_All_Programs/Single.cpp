#include<iostream>
using namespace std;

class Shape
{
protected:
	int height, width;
public:
	void setDimensions(int height,int width)
	{
		this->height = height;
		this->width = width;
	}
};

class Rectangle : public Shape
{
public:
	int getArea()
	{
		return width * height;
	}
};

int main()
{
	Rectangle rect;
	rect.setDimensions(3,6);
	cout<<" Area Of Rectangle "<< rect.getArea()<<endl;
	return 0;
}