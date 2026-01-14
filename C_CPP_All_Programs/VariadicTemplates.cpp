/*
Variadic Templates – C++11:
Variadic templates allow functions and classes to accept a variable number of template parameters.
They provide type-safe alternatives to C-style variadic functions (va_list).
Implemented using parameter packs and recursion or fold expressions (C++17).
*/

#include <iostream>
using namespace std;

// Base case: single argument
template<typename T>
void print(T value) 
{
    cout << value << endl;
}

// Recursive variadic template
template<typename T, typename... Args>
void print(T first, Args... rest) 
{
    cout << first << " ";
    print(rest...);   // unpack parameter pack
}

int main() 
{
    print(10, 3.14, "Hello", 'A');
    return 0;
}
