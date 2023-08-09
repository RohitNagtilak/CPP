#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
const int N = 5;
mutex M[N];
void pick_forks(int philosopher_id, int fork1, int fork2) 
{
    unique_lock<mutex> fork1_lock(M[fork1]);
    this_thread::sleep_for(chrono::milliseconds(100)); // Thinking
    unique_lock<mutex> fork2_lock(M[fork2]);
}

void philosopher(int id)
{
    int left_fork = id;
    int right_fork = (id + 1) % N;
    // Pick up forks in order to prevent deadlock
    if (id % 2 == 0)
        pick_forks(id, left_fork, right_fork);
    else
        pick_forks(id, right_fork, left_fork);
    // Eating
    cout << "Philosopher " << id << " is eating." << endl;
    M[right_fork].unlock();
    M[left_fork].unlock();
    // Thinking
    cout << "Philosopher " << id << " is done eating and thinking." << endl;
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