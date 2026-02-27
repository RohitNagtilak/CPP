//Returning an Exception from a Thread
//	- Normal threads(std::thread) cannot directly propagate exceptions to the caller.
//	- If a thread throws an exception, it will terminate the program unless handled inside the thread
//
//How to Return an Exception Safely
//	- Use std::promise + std::future to pass the exception from the thread to the caller.

#include <iostream>
#include <thread>
#include <future>
#include <exception>

void threadFunc(std::promise<int>& p) {
    try {
        throw std::runtime_error("Error in thread!"); // exception occurs
        p.set_value(42); // won't reach here
    }
    catch (...) {
        p.set_exception(std::current_exception()); // pass exception to future
    }
}

int main() 
{
    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::thread t(threadFunc, std::ref(p));

    try
    {
        int result = f.get(); // will re-throw exception here
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception from thread: " << e.what() << std::endl;
    }

    t.join();
}

//  Exceptions cannot propagate automatically from std::thread.
//  Use std::promise + std::future to transfer exception safely.
//  std::future::get() will rethrow the exception in the calling thread.
