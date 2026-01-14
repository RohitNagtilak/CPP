/*
constexpr – C++11:
constexpr allows compile-time evaluation of values and functions.
It improves performance and ensures constants are known at compile time.
*/

#include <iostream>

// constexpr function
constexpr int square(int x) 
{
    return x * x;
}

constexpr int ARRAY_SIZE = square(4);

int main() 
{
    int arr[ARRAY_SIZE];   // OK

    constexpr int value = square(5);
    int runtimeValue = square(3);

    std::cout << value << " " << runtimeValue << std::endl;
    return 0;
}
