//What is std::packaged_task ?
//- std::packaged_task wraps a callable(function, lambda, functor) so it can be executed asynchronously.
//- It is linked to a std::future, which lets you get the result later.
//- Useful when you want to run a function in another thread and retrieve the return value safely.

#include <iostream>
#include <future>
#include <thread>

int compute(int x) { return x * 2; }

int main()
{
    // Wrap function in packaged_task
    std::packaged_task<int(int)> task(compute);

    // Get future to retrieve result later
    std::future<int> fut = task.get_future();

    // Run task in a separate thread
    std::thread t(std::move(task), 5);

    // Wait and get result
    std::cout << "Result: " << fut.get() << std::endl;

    t.join();
}

//std::packaged_task → wraps a function to run asynchronously.
//std::future → retrieves the result later.
//Can be run with std::thread or executed later manually.