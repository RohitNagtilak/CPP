#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

const int N = 5;
mutex M[N];

void philosopher(int id)
{
    int left_fork = id;
    int right_fork = (id + 1) % N;

    // Thinking before trying to pick up forks
    this_thread::sleep_for(chrono::milliseconds(100));

    // Pick up forks in order to prevent deadlock
    // Use scoped_lock to lock both mutexes safely (no manual unlocks).
    if (id % 2 == 0)
    {
        scoped_lock lock(M[left_fork], M[right_fork]);
        // Eating
        cout << "\nPhilosopher " << id << " is eating." << endl;
        this_thread::sleep_for(chrono::milliseconds(100)); // simulate eating
        // Locks released automatically when 'lock' goes out of scope
    }
    else
    {
        scoped_lock lock(M[right_fork], M[left_fork]);
        // Eating
        cout << "\nPhilosopher " << id << " is eating." << endl;
        this_thread::sleep_for(chrono::milliseconds(100)); // simulate eating
        // Locks released automatically when 'lock' goes out of scope
    }

    // Thinking
    cout << "\nPhilosopher " << id << " is done eating and thinking." << endl;
}

int main()
{
    thread philosophers[N];
    for (int i = 0; i < N; ++i)
        philosophers[i] = thread(philosopher, i);

    for (int i = 0; i < N; ++i)
        philosophers[i].join();
    return 0;
}