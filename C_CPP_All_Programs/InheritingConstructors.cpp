/*
Inheriting Constructors – C++11:
Inheriting constructors allows a derived class to reuse constructors
of its base class using `using Base::Base`, reducing boilerplate code.
Only base-class constructors are inherited; new members must be handled separately.
*/

#include <iostream>
using namespace std;

class Base 
{
protected:
    int x;

public:
    Base(int v) : x(v) {}
    Base(int a, int b) : x(a + b) {}
};

class Derived : public Base 
{
public:
    using Base::Base;   // inherit all Base constructors

    void print() const {
        cout << "x = " << x << endl;
    }
};

int main() 
{
    Derived d1(10);      // calls Base(int)
    Derived d2(3, 7);   // calls Base(int, int)

    d1.print();
    d2.print();
    return 0;
}
