#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

int myAmount = 0;
mutex m1;

void AddMoney()
{
	lock_guard<mutex> lock(m1);
	++myAmount;
	cout << " " << myAmount << endl;
}

int main()
{
	thread t1(AddMoney);
	thread t2(AddMoney);
	t1.join();
	t2.join();

	return 0;
}