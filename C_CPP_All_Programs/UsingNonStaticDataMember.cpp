#include<iostream>
#include<thread>
using namespace std;
class Sample
{
public:
	void Run(int num)
	{
		for (int i = 0; i < num; i++)
			cout << " "<<i << endl;
	}
};
int main()
{
	Sample s1;
	thread t1(&Sample::Run, &s1,20);
	thread t2(&Sample::Run, &s1,30);
	t1.join();
	t2.join();
	return 0;
}