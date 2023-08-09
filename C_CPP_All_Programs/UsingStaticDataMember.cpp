#include<iostream>
#include<Thread>
using namespace std;
class Sample
{
public:
	static void Run(int num)
	{
		for (int i = 0; i < num; i++)
		{
			cout << " " << i << endl;
		}
	}
};

int main()
{
	thread t1(&Sample::Run, 20);
	thread t2(&Sample::Run, 30);
	
	if(t1.joinable())
	t1.join();

	//t1.join(); // It will through an error.

	if(t2.joinable())
	t2.join();

	return 0;
}