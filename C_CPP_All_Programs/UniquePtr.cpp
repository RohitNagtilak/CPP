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
		cout << "Constructor Called"<<endl;
	}
	~Sample()
	{
		cout << "Destructor Called" << endl;
	}
};

int main()
{
	unique_ptr<Sample> obj1(new Sample());
	obj1->Display();


	// Using std::make_unique (Exception Safe)
	std::unique_ptr<Sample> ptr = std::make_unique<Sample>();
	ptr->Display();

	// ptr is automatically deleted when it goes out of scopess
	return 0;
}