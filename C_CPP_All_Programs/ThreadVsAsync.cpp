#include <iostream>
#include <thread>
#include <future>
using namespace std;

// Function to compute square
int compute(int x) { return x * x; }

int main() 
{
    cout << "=== std::thread ===\n";
    int resultThread = 0;

    thread t([&]() { resultThread = compute(5); }); // thread needs manual storage
    t.join(); // must join manually
    cout << "Thread result: " << resultThread << endl;

    cout << "\n=== std::async ===\n";
    future<int> fut = async(compute, 5); // async returns future automatically
    int resultAsync = fut.get();          // waits and gets result
    cout << "Async result: " << resultAsync << endl;

    return 0;
}
