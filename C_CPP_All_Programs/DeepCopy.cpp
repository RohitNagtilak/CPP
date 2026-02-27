#include <iostream>
#include <utility>

using namespace std;

class Test
{
public:
    int* data;
    Test() : data(nullptr) {}

    Test(const Test& obj) : data(nullptr)
    {
        if (obj.data)
        {
            data = new int(*(obj.data));
        }
    }

    Test(Test&& other) noexcept : data(other.data)
    {
        other.data = nullptr;
    }

    Test& operator=(const Test& other)
    {
        if (this == &other) return *this;
        Test tmp(other);        // may throw, but leaves *this unchanged
        swap(tmp);              // noexcept
        return *this;
    }

    Test& operator=(Test&& other) noexcept
    {
        if (this == &other) return *this;
        delete data;
        data = other.data;
        other.data = nullptr;
        return *this;
    }

    // destructor
    ~Test()
    {
        delete data;
        data = nullptr;
    }

    // swap helper
    void swap(Test& other) noexcept
    {
        std::swap(data, other.data);
    }
};

int main()
{
    Test p;
    p.data = new int(10);
    cout << "P -> Data= " << (p.data ? *(p.data) : 0) << endl;

    Test q(p); // deep copy
    cout << "Q -> Data= " << (q.data ? *(q.data) : 0) << endl;

    if (q.data) *(q.data) = 30;
    cout << "P -> Data= " << (p.data ? *(p.data) : 0) << endl;
    cout << "Q -> Data= " << (q.data ? *(q.data) : 0) << endl;

    return 0;
}