#include<iostream>
#include<memory>

using namespace std;

class Sample
{
public:
	void Display()
	{
		cout << "Sample Class" << endl;
	}
	Sample()
	{
		cout << "Constructor Called" << endl;
	}
	~Sample()
	{
		cout << "Destructor Called" << endl;
	}
};
void Process(unique_ptr<Sample> obj)
{
	obj->Display();
}
int main()
{
	// Using std::make_unique
	std::unique_ptr<Sample> ptr = std::make_unique<Sample>();

	Process(move(ptr));
	
	// It will give warning if we try to use ptr which is moved.
	// ptr->Display();
	//
	// ptr is automatically deleted when it goes out of scope
	return 0;
}