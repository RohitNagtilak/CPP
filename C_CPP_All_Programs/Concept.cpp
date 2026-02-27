#include<iostream>
using namespace std;
//template <typename T>
class MyPtrClass
{
public:
	MyPtrClass()
	{
		data = nullptr;
	}

	MyPtrClass(/*T*/int* p)
	{
		cout << "\n Constructor Called \n";
		data = p;
	}

	~MyPtrClass()
	{
		cout << "\n Destructor Called \n";
		delete data;
	}

	/*T*/int& operator*()
	{
		return *data;
	}
private:
	/*T*/int* data;
};

int main()
{
	//MyPtrClass<string> strPtr(new string("Rohit"));
	//cout << "Value is :" << *strPtr;

	//MyPtrClass<int> intPtr(new int(10));
	//cout << "Value is :" << *intPtr;

	//MyPtrClass<double> doublePtr(new double(1.5));
	//cout << "Value is :" << *doublePtr;

	MyPtrClass intPtr(new int(10));

	return 0;
}