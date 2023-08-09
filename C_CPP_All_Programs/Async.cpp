#include <iostream>
#include <future>
using namespace std;

int Sum(int a, int b)
{
    return a + b;
}

int main()
{
    // Using std::launch::async
    future<int> asyncResult = async(std::launch::async, Sum, 10, 20);

    // Using std::launch::deferred
    future<int> deferredResult = async(std::launch::deferred, Sum, 30, 40);

    // Since the deferredResult uses std::launch::deferred, the task is not executed yet
    // It will be executed lazily when calling get() or wait()

    // Getting the result from asyncResult
    int sumAsync = asyncResult.get();
    cout << "Sum using std::launch::async: " << sumAsync << endl;

    // Getting the result from deferredResult
    int sumDeferred = deferredResult.get();
    cout << "Sum using std::launch::deferred: " << sumDeferred << endl;

    return 0;
}
