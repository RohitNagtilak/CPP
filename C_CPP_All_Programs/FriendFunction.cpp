#include<iostream>
using namespace std;

class B;
class A
{
public:
	void Display(B& obj);
};

class B
{
private:
	int m_private = 10;
	void Private()
	{
		cout << "Private Method" << endl;
	}
	void friend A::Display(B& obj);
};

void A::Display(B& obj)
{
	cout << "m_private =" << obj.m_private << endl;
	obj.Private();
}

int main()
{
	B object1;
	A object2;
	object2.Display(object1);
	return 0;
}