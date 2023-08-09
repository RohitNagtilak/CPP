#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
#include<Windows.h>

using namespace std;
timed_mutex mtx;

void Function()
{
    if (mtx.try_lock_for(chrono::milliseconds(100)))
    {
        cout << "Mutex locked successfully!" << endl;
        // Sleep(100);
        mtx.unlock();
    }
    else
    {
        cout << "Failed to lock the mutex!" << endl;
    }
}
int main()
{
    thread t1(Function);
    thread t2(Function);
    t1.join();
    t2.join();
    return 0;
}
