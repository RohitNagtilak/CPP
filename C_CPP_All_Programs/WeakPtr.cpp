#include<iostream>
using namespace std;
int main()
{
	auto sharedPtr = make_shared<int>(int(100));
	weak_ptr<int> weakPtr(sharedPtr);

	cout << "shared_ptr UseCount = " << sharedPtr.use_count() << endl;
	cout << "Weak_ptr UseCount = " << weakPtr.use_count() << endl;
	cout << "Weak_ptr.expired() = " << weakPtr.expired() << endl<<endl;

	if (shared_ptr<int> shPtr = weakPtr.lock())
	{
		cout << "*shPtr = " << *shPtr<<endl;
		cout << "shared_ptr UseCount = " << sharedPtr.use_count() << endl;
	}
	else
	{
		cout << "Resource Not Found..!"<<endl;
	}
	
	weakPtr.reset();
	if (shared_ptr<int> shPtr = weakPtr.lock())
	{
		cout << "*shPtr = " << *shPtr<<endl;
		cout << "shared_ptr UseCount = " << sharedPtr.use_count() << endl;
	}
	else
	{
		cout << "Resource Not Found..!"<<endl;
	}

	return 0;
}