#include<iostream>
using namespace std;

class Base1
{
public:
    int value;
};

class Base2
{
public:
    int value;
};

class Derived : public Base1, public Base2
{
public:
    void setValue(int x)
    {
        Base1::value = x;
    }
};

int main()
{
    Derived d;
    d.setValue(10);

    Base1* b1;
    Base2* b2;

    b1 = &d;
    b2 = &d;
    cout << "b1 " << b1->value << endl << "b2 " << b2->value << endl;

    return 0;
}