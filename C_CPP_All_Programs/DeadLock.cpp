//A deadlock is a situation in which two or more threads are waiting for each other to release 
//a resource that they are holding
#include<iostream>
#include<mutex>
#include<thread>

using namespace std;
mutex m1,m2;

void Fun1()
{
	cout << "Fun1" << endl;
	m1.lock();
	m2.lock();
	cout << "Lock Acquired..! Fun1" << endl;
	m1.unlock();
	m2.unlock();
}
void Fun2()
{
	cout << "Fun2" << endl;
	m2.lock();
	m1.lock();
	cout << "Lock Acquired..! Fun2" << endl;
	m2.unlock();
	m1.unlock();
}

int main()
{
	thread t1(Fun1);
	thread t2(Fun2);
	t1.join();
	t2.join();
	return 0;
}