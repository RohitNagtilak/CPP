// WHY use std::atomic?
// To safely share and modify a variable across multiple threads without locks.
//
// WHY it is important?
// Prevents data races and undefined behavior while providing fast,lock-free synchronization.
//
// METHODS:
// load()              → Atomically reads the value
// store(val)          → Atomically writes a value
// fetch_add(n)        → Atomically adds n and returns old value
// exchange(val)       → Atomically replaces value and returns old value
// compare_exchange_*  → Atomically compares and updates value (CAS, lock-free sync)

#include <iostream>
#include <atomic>
#include <thread>

using namespace std;

/*
 Atomic integer shared across threads
*/
atomic<int> counter{ 0 };

/*========================================================
  Worker demonstrates fetch_add
========================================================*/
void incrementWorker()
{
    // Atomically add 1 and return OLD value
    int old = counter.fetch_add(1);
    cout << "fetch_add -> old value: " << old << endl;
}

/*========================================================
  Worker demonstrates compare_exchange
========================================================*/
void casWorker()
{
    int expected = 2;

    /*
     If counter == expected,
     then replace counter with 100
    */
    bool success = counter.compare_exchange_strong(expected, 100);

    cout << "compare_exchange -> success: "
        << success << ", counter: " << counter.load() << endl;
}

int main()
{
    /*====================================================
      1️⃣ store() — Atomic write
    ====================================================*/
    counter.store(0);
    cout << "store(0) -> counter: " << counter.load() << endl;

    /*====================================================
      2️⃣ load() — Atomic read
    ====================================================*/
    int value = counter.load();
    cout << "load() -> counter: " << value << endl;

    /*====================================================
      3️⃣ fetch_add() — Atomic increment
    ====================================================*/
    thread t1(incrementWorker);
    thread t2(incrementWorker);

    t1.join();
    t2.join();

    cout << "After fetch_add -> counter: "
        << counter.load() << endl;

    /*====================================================
      4️⃣ exchange() — Atomic replace
    ====================================================*/
    int oldValue = counter.exchange(50);
    cout << "exchange(50) -> old: " << oldValue
        << ", new: " << counter.load() << endl;

    /*====================================================
      5️⃣ compare_exchange_strong() — CAS
    ====================================================*/
    thread t3(casWorker);
    t3.join();

    /*====================================================
      6️⃣ compare_exchange_weak() — CAS (loop usage)
    ====================================================*/
    int expected = counter.load();

    while (!counter.compare_exchange_weak(expected, 200))
    {
        // expected is updated automatically
        cout << "CAS weak failed, retrying...\n";
    }

    cout << "compare_exchange_weak -> counter: "
        << counter.load() << endl;

    return 0;
}
