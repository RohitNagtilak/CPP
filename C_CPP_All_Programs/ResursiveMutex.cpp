#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

recursive_mutex mtx;
void recursiveFunction(int count)
{
    mtx.lock();
    if (count > 0)
    {
        std::cout << "Count: " << count << std::endl;
        recursiveFunction(count - 1);
    }
    mtx.unlock();
}

int main()
{
    thread t1(recursiveFunction, 10);
    thread t2(recursiveFunction, 5);
    t1.join();
    t2.join();
    return 0;
}
