#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
	Test()
	{
		cout << "Constructor Called." << endl;
	}
	~Test()
	{
		cout << "Destructor Called." << endl;
	}
};

int main()
{
	Test s;

	Test* s1 = new Test();
	delete s1;

	//unique_ptr<Test> s2(new Test());
	unique_ptr<Test> s2 = make_unique<Test>();
	return 0;
}