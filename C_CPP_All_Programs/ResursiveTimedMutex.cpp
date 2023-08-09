#include <iostream>
#include <mutex>
#include <thread>

std::recursive_timed_mutex mutex;

void recursive_function(int depth)
{
    std::unique_lock<std::recursive_timed_mutex> lock(mutex, std::defer_lock);
    if (lock.try_lock_for(std::chrono::milliseconds(1))) 
    {
        std::cout << "Depth " << depth << ": Mutex acquired" << std::endl;
        recursive_function(depth + 1);
        lock.unlock();
    }
    else
    {
        std::cout << "Depth " << depth << ": Failed to acquire mutex" << std::endl;
    }
}

int main()
{
    recursive_function(1);

    return 0;
}
