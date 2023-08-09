#include<iostream>
using namespace std;
class DeepCpy
{
public:
	DeepCpy();
	DeepCpy(int);
	DeepCpy(DeepCpy&);
	~DeepCpy();
	void Display();
	void SetValue(int);

private:
	int* a = new int;
};

DeepCpy::DeepCpy()
{
}

DeepCpy::DeepCpy(int a)
{
	*(this->a) = a;
}

DeepCpy::DeepCpy(DeepCpy& obj1)
{
	cout << "DeepCpy constructor called" << endl;
	this->a = new int;
	*(this->a) = *obj1.a;
}

DeepCpy::~DeepCpy()
{
	delete a;
}

void DeepCpy::Display()
{
	cout << " Value of  a =" << *(this->a) << endl;
}

void DeepCpy::SetValue(int a)
{
	*(this->a) = a;
}

int main()
{
	DeepCpy Obj1(10);
	cout << "Obj1:" << endl;
	Obj1.Display();

	cout << "Obj2:" << endl;
	DeepCpy Obj2(Obj1);
	Obj2.Display();

	Obj2.SetValue(20);
	cout << "Obj2:" << endl;
	Obj2.Display();

	cout << "Obj1:" << endl;
	Obj1.Display();
}