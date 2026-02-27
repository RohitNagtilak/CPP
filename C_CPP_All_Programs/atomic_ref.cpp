// WHY use std::atomic_ref?
// To perform atomic operations on an existing non-atomic variable without changing its type.
//
// WHY it is important?
// Enables thread safety in legacy or third-party code where data structures cannot be modified.
//
// METHODS (one-line description):
// load()              → Atomically reads the referenced variable
// store(val)          → Atomically writes to the referenced variable
// fetch_add(n)        → Atomically modifies the referenced variable
// exchange(val)       → Atomically replaces value and returns old value
// compare_exchange_*  → Lock-free compare-and-swap on referenced variable

#include <atomic>
#include <thread>
#include <iostream>

using namespace std;

struct Data
{
    int value;   // Non-atomic variable
};

Data data{ 0 };

void worker()
{
    std::atomic_ref<int> ref(data.value); // Atomic view over existing variable
    ref.fetch_add(1);
}

int main()
{
    thread t1(worker);
    thread t2(worker);

    t1.join();
    t2.join();

    cout << data.value << endl;
}
