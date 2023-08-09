#include<iostream>
using namespace std;
class B;
class A
{
	int m_private = 10;
	void PrivateMethod()
	{
		cout << "Private Method of Class A. " << endl;

	}
protected:
	int m_protected = 20;
	const void ProtectedMethod()
	{
		cout << "Protected Method of Class A. " << endl;
	}
	friend B;
};

class B
{
public:
	void PrivateNProtectedDataOfA(A &obj)
	{
		cout << "m_private ="<<obj.m_private << endl;
		obj.PrivateMethod();

		cout << "m_protected = " << obj.m_protected<<endl;
		obj.ProtectedMethod();
	}
};

int main()
{
	A obj;
	B objB;
	objB.PrivateNProtectedDataOfA(obj);
	return 0;
}