#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

int myAmount = 0;
mutex m1;

void AddMoney()
{
	m1.lock();
	++myAmount;
	cout << " " << myAmount << endl;
	m1.unlock();
}

int main()
{
	thread t1(AddMoney);
	thread t2(AddMoney);
	t1.join();
	t2.join();

	return 0;
}