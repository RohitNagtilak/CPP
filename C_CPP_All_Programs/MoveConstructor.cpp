//Called when an object is created from an rvalue

#include <iostream>
using namespace std;

class Test 
{
public:
    int* data;

    Test(int v) 
    {
        data = new int(v);
    }

    // Copy constructor
    Test(const Test& t)
    {
        data = new int(*t.data);
        cout << "Copy constructor\n";
    }

    // Move constructor
    Test(Test&& t) noexcept 
    {
        data = t.data;
        t.data = nullptr;
        cout << "Move constructor\n";
    }

    ~Test() 
    {
        delete data;
    }
};

int main()
{
    Test a(10);
    Test b(a);              // copy
    Test c(std::move(a));   // move
}
