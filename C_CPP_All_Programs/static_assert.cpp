/*
static_assert – C++11:
static_assert performs compile-time checks and stops compilation if the condition is false.
It is used to enforce constraints, validate template parameters, and catch errors early.
Unlike runtime assertions, it has zero runtime cost.
*/

#include <iostream>
using namespace std;

template<typename T>
class Data 
{
    static_assert(sizeof(T) <= 4, "Type size must be 4 bytes or less"); // compile-time check
public:
    T value;
};

int main() 
{
    static_assert(sizeof(int) == 4, "int must be 4 bytes"); // compile-time validation

    Data<int> d;      // OK
    // Data<double> x; // ❌ compilation error (static_assert fails)

    cout << "Program compiled successfully\n";
    return 0;
}
