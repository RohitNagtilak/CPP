#include<iostream>
#include<thread>
#include<mutex>
#include<Windows.h>

using namespace std;
int myAmount = 0;
mutex m1, m2;

void AddMoney()
{
	int result = try_lock(m1, m2);

	if (result == -1)
	{
		++myAmount;
		cout << " " << myAmount << endl;
		cout << "result = " << result << endl;
		m1.unlock();
		m2.unlock();
	}
}

int main()
{

	thread t1(AddMoney);
	Sleep(2);
	thread t2(AddMoney);
	t1.join();
	t2.join();

	return 0;
}