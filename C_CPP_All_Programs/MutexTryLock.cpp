#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

int myAmount = 0;
mutex m1;

void AddMoney()
{
	if (m1.try_lock())
	{
		++myAmount;
		cout << " " << myAmount << endl;
		m1.unlock();
	}
	else
	{
		cout << this_thread::get_id() << " Failed to acquire lock..!" << endl;
	}
}

int main()
{
	thread t1(AddMoney);
	thread t2(AddMoney);
	t1.join();
	t2.join();

	return 0;
}