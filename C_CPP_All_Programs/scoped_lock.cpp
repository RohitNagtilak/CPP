#include <iostream>
#include <mutex>
#include <thread>
//#include<Windows.h>
std::mutex mutex1;
std::mutex mutex2;

void threadFunction()
{
    std::scoped_lock lock(mutex1, mutex2);
    // Critical section protected by mutex1 and mutex2
    std::cout << "Thread acquired both locks" << std::endl;
}

int main() 
{
    std::thread t(threadFunction);
   //Sleep(2);
    {
        std::scoped_lock lock(mutex1, mutex2);
        // Critical section protected by mutex1 and mutex2
        std::cout << "Main thread acquired both locks" << std::endl;
    }

    t.join();

    return 0;
}
