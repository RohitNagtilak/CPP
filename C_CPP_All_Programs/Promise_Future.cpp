#include<iostream>
#include<thread>
#include<future>
using namespace std;

void Add(promise<int>&& promise, int a, int b)
{
	promise.set_value(a + b);
}

int main()
{
	promise<int> promise;
	future<int> future = promise.get_future();

	thread t1(Add, move(promise), 10, 20);

	cout << "waiting.." << endl;
	cout << "Value is= " << future.get() << endl;
	t1.join();

	return 0;
}