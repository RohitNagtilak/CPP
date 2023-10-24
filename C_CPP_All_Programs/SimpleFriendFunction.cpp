#include<iostream>
using namespace std;
class A
{
protected:
	int protectedData = 20;
private:
	int privatedata = 10;
	friend void Display(A&);
};

void Display(A& obj)
{
	cout << "Data = " << obj.privatedata << endl;
	cout << "Data = " << obj.protectedData << endl;
}

int main()
{
	A a;
	Display(a);
	return 0;
}