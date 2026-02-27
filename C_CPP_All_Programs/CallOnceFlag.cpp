//std::once_flag → keeps track of whether the function has run.
//std::call_once → ensures the function is executed only once, even in multiple threads.
//Use std::call_once with std::once_flag to call a function only once across threads.

#include <iostream>
#include <thread>
#include <mutex>

std::once_flag flag;

void init()
{
    std::cout << "Function called only once!\n";
}

void threadFunc() 
{
    std::call_once(flag, init); // guarantees init runs only once
}

int main() 
{
    std::thread t1(threadFunc);
    std::thread t2(threadFunc);
    std::thread t3(threadFunc);

    t1.join();
    t2.join();
    t3.join();
}
