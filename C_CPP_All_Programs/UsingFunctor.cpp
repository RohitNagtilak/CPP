#include<iostream>
#include<thread>
using namespace std;
class Number
{
public:
	void operator()()
	{
		for (int i = 0; i < 26; i++)
			cout << " " << i << endl;
	}
};
int main()
{
	thread t1((Number()));
	thread t2((Number()));
	t1.join();
	t2.join();
	return 0;
}