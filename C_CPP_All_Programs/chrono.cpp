// To measure time, durations, and timestamps in a precise, type-safe, and portable way.
//
// WHY it is important?
// ----------------------------------------
// Avoids bugs from raw integers (ms/sec mix-ups) and provides high-resolution, steady clocks
// suitable for performance measurement and time-based logic.
//
// MAIN TYPES & METHODS:
// std::chrono::duration        → Represents a length of time (e.g., seconds, milliseconds)
// std::chrono::time_point      → Represents a point in time from a specific clock
// steady_clock::now()          → Returns a monotonic time point (safe for measuring intervals)
// system_clock::now()          → Returns current wall-clock time (date/time)
// high_resolution_clock::now() → Highest available resolution clock (may alias others)
// duration_cast<T>()           → Converts one duration type to another safely
// time_since_epoch()           → Gets duration since clock’s epoch

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    // Capture start time using a steady clock (best for measuring elapsed time)
    auto start = chrono::steady_clock::now();

    // Simulate some work
    this_thread::sleep_for(chrono::milliseconds(500));

    // Capture end time
    auto end = chrono::steady_clock::now();

    // Compute elapsed time as a duration
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Elapsed time: " << elapsed.count() << " ms" << endl;

    return 0;
}
