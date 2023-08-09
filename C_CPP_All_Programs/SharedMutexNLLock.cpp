#include <iostream>
#include <shared_mutex>
#include <thread>
#include <vector>
using namespace std;
vector<int> sharedData;
shared_mutex mut;

void readData()
{
    shared_lock<std::shared_mutex> lock(mut);
    cout << "Reading data: ";
    for (const auto& data : sharedData)
    {
        cout << data << " ";
    }
    std::cout << std::endl;
}

void writeData(int newData) 
{
    std::unique_lock<std::shared_mutex> lock(mut);
    sharedData.push_back(newData);
    std::cout << "Writing data: " << newData << std::endl;
}

int main()
{
    std::thread readerThread1(readData);
    std::thread readerThread2(readData);
    std::thread writerThread1(writeData, 42);
    std::thread readerThread3(readData);

    readerThread1.join();
    readerThread2.join();
    writerThread1.join();
    readerThread3.join();

    return 0;
}