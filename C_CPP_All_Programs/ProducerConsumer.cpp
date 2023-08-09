#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;

mutex mtx;
condition_variable cv;
queue<int> buffer;
const int BUFFER_SIZE = 10;

void producer()
{
    for (int i = 0; i < 20; ++i)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < BUFFER_SIZE; });

        buffer.push(i);
        cout << "Produced: " << i << endl;

        lock.unlock();
        cv.notify_all();

        // Simulate some work being done by the producer
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer()
{
    for (int i = 0; i < 20; ++i)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty(); });

        int item = buffer.front();
        buffer.pop();
        cout << "Consumed: " << item << endl;

        lock.unlock();
        cv.notify_all();

        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

int main()
{
    thread producerThread(producer);
    thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();
    return 0;
}
