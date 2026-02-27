#include<iostream>
using namespace std;

class Demo
{
public:

	void Display()
	{
		cout << "Demo Class" << endl;
	}

	Demo()
	{
		cout << "Constructor Called" << endl;
	}

	~Demo()
	{
		cout << "Destructor Called" << endl;
	}
};

int main()
{
	unique_ptr<Demo> obj1(new Demo());
	obj1->Display();

	// Using std::make_unique (Exception Safe)
	unique_ptr<Demo> obj2 = make_unique<Demo>();
	obj2->Display();

	// ptr is automatically deleted when it goes out of scope

	return 0;
}