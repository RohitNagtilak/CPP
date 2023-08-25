#include<iostream>
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
	
	Test *s1 = new Test();
	delete s1;
	
	unique_ptr<Test> s2(new Test());
	return 0;
}