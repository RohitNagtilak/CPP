//std::jthread vs std::thread
//- std::thread → manual join() or detach().Forgetting join can crash program.
//- std::jthread(C++20) → automatically joins on destruction, safer and cleaner.
//- Extra: supports cooperative cancellation via stop_token.

//std::thread t1(work);  t1.join();   // manual join
//std::jthread t2(work);              // auto-join on scope exit

//Key: Use jthread in C++20 to avoid manual joins and improve safety.

#include <iostream>
#include <thread>

void work() 
{
    std::cout << "Thread working\n";
}

int main() 
{
    // std::thread
    std::thread t1(work);
    t1.join(); // must join manually

    // std::jthread (C++20)
    std::jthread t2(work); // automatically joins on scope exit
}
