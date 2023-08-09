#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

mutex m;
condition_variable cv;
int num = 1;

void PrintEven()
{
	for (; num <= 10;)
	{
		unique_lock<mutex> lock(m);
		cv.wait(lock, []() {return num % 2 == 0;});
		cout << "Even ="  ;
		cout << num << " "<<endl;
		num++;
		cv.notify_all();
	}
}

void PrintOdd()
{
	for (; num <= 10;)
	{
		unique_lock<mutex> lock(m);
		cv.wait(lock, []() {return num % 2 == 1; });
		//cv.wait_for();;
		//cv.wait_until();;
		cout << "Odd  =" ;
		cout << num << " "<<endl;
		num++;
		cv.notify_all();
	}
}

int main()
{
	thread t1(PrintEven);
	thread t2(PrintOdd);
	t1.join();
	t2.join();
	return 0;
}