#include<iostream>
using namespace std;

class Simple
{
public:
	Simple()
	{
		cout << "Constructor Called." << endl;
	}
	~Simple()
	{
		cout << "Destructor Called." << endl;
	}
};

int main()
{
	Simple s;
	Simple *s1 = new Simple();
	unique_ptr<Simple> s2(new Simple());
	delete s1;
	return 0;
}