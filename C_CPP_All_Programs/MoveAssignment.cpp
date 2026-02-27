//Called when an existing object is assigned from an rvalue
#include <iostream>
using namespace std;

class Test 
{
public:
    int* data;

    Test(int v) { data = new int(v); }

    // Move assignment
    Test& operator=(Test&& t) noexcept 
    {
        if (this != &t)
        {
            delete data;       // clean old resource
            data = t.data;    // steal
            t.data = nullptr;
        }
        return *this;
    }

    ~Test() { delete data; }
};

int main() 
{
    Test a(10);
    Test b(20);

    b = std::move(a);   // move assignment
}
