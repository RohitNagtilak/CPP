#include<iostream>
using namespace std;
template <typename T>
class MyPtrClass
{
public:
	MyPtrClass()
	{
		data = nullptr;
	}

	MyPtrClass(T *p)
	{
		cout << "\nConstructor Called\n";
		data = p;
	}
	
	~MyPtrClass()
	{
		cout << "\nDestructor Called\n";
		delete data;
	}

	T& operator*()
	{
		return *data;
	}
private:
	T* data;
};

int main()
{
	MyPtrClass<string> strPtr(new string("Rohit"));
	cout << "Value is :" << *strPtr;

	MyPtrClass<int> intPtr(new int(10));
	cout << "Value is :" << *intPtr;

	MyPtrClass<double> doublePtr(new double(1.5));
	cout << "Value is :" << *doublePtr;

	return 0;
}