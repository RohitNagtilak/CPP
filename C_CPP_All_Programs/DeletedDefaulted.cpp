/*
    `= delete` explicitly disables unwanted functions (like copy or default construction).
    `= default` tells the compiler to generate the default implementation.

    They improve code clarity, correctness, and intent expression.
*/

#include <iostream>
using namespace std;

class Test 
{
public:
    int x;

    Test() = default;                 // compiler-generated default constructor

    Test(int v) : x(v) {}

    Test(const Test&) = delete;       // disable copy constructor
    Test& operator=(const Test&) = delete; // disable copy assignment

    Test(Test&&) = default;           // enable move constructor
    Test& operator=(Test&&) = default; // enable move assignment
};

int main() 
{
    Test a(10);

    // Test b(a);        // ❌ copy constructor deleted
    // b = a;            // ❌ copy assignment deleted

    Test c(std::move(a));  // move allowed
    cout << "Program compiled successfully\n";

    return 0;
}
