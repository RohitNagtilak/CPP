#include<iostream>
using namespace std;

class Number
{
	int num;
public:
	Number(){}
	Number(int num)
	{
		this->num = num;
	}

	Number operator+(Number& obj)
	{
		return this->num + obj.num;
	}

	void Display()
	{
		cout << "Number is : " << num << endl;
	}
};

int main()
{
	Number a(10);
	a.Display();

	Number b(20);
	b.Display();

	Number c = a + b;
	c.Display();

	return 0;
}