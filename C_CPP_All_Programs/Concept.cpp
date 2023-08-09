#include<iostream>
using namespace std;

class MyPtrClass
{
public:
	MyPtrClass()
	{
		data = nullptr;
	}

	MyPtrClass(int *p)
	{
		data = p;
	}
	
	~MyPtrClass()
	{
		delete data;
	}

	int& operator*()
	{
		return *data;
	}
private:
	int* data;
};
int main()
{
	int* ptr = new int(5);
	MyPtrClass p = MyPtrClass(ptr);
	cout << "Value " << *p;
	return 0;
}