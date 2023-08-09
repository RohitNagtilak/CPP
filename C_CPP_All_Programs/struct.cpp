#include<iostream>
using namespace std;

struct Rectangle
{
	int width;
	int height;
	void display()
	{
		cout << "Width =" << width << " Height =" << height<<endl;
	}
};

int main()
{
	Rectangle a;
	a.width = 10;
	a.height = 20;
	a.display();

	return 0;
}