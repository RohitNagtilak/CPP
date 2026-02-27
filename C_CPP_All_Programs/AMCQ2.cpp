/*
    There is an algorithm that is divided into 5 parts.
    They must be executed one by one in different threads, using the result of the previous step.
    How do you implement it?

*/

// Each thread represents a step of the algorithm.
// Condition variable ensures that step i waits until step i - 1 is finished.
// currentStep tracks the latest completed step.
// Once a step is done, it notifies the next thread using cv.notify_all().

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

const int STEPS = 5;
int results[STEPS]; // store results of each step

mutex mtx;
condition_variable cv;
int currentStep = 0; // tracks which step is completed

// Function for step i
void stepFunction(int stepIndex) 
{
    unique_lock<mutex> lock(mtx);
    // Wait until previous step is done
    cv.wait(lock, [stepIndex]() { return stepIndex == 0 || stepIndex == currentStep; });

    // --- Execute the step ---
    results[stepIndex] = stepIndex * 10; // example computation
    cout << "Step " << stepIndex << " done, result = " << results[stepIndex] << endl;

    // Mark this step as completed
    currentStep = stepIndex + 1;
    lock.unlock();
    cv.notify_all(); // notify the next step
}

int main() 
{
    vector<thread> threads;

    // Launch threads for steps 0 to 4
    for (int i = 0; i < STEPS; ++i) 
    {
        threads.emplace_back(stepFunction, i);
    }

    // Join all threads
    for (auto& t : threads) 
    {
        t.join();
    }

    cout << "All steps completed." << endl;
    return 0;
}
