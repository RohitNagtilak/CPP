/*
    Delegating constructors allow one constructor to call another constructor
    of the same class to reuse initialization logic and avoid code duplication.
    The delegated constructor must appear in the initializer list.
*/

#include <iostream>
using namespace std;

class Test 
{
    int x, y;

public:
    // Primary constructor
    Test(int a, int b) : x(a), y(b) {}

    // Delegating constructor
    Test(int a) : Test(a, 0) {}   // delegates to Test(int, int)

    // Delegating to default values
    Test() : Test(0, 0) {}

    void print() const 
    {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

int main() 
{
    Test t1(10, 20);
    Test t2(5);
    Test t3;

    t1.print();
    t2.print();
    t3.print();

    return 0;
}
