#include<iostream>
using namespace std;

class Number
{
	int num = 0;
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
	Number obj1(10);
	Number obj2(20);

	Number obj3 = obj1 + obj2;
	obj3.Display();

	return 0;
}