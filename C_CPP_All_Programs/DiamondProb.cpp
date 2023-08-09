// Online C++ compiler to run C++ program online
#include <iostream>

class Base
{
public:
    int value;
};

class Derived1 : public virtual Base
{

};

class Derived2 : public virtual Base
{

};

class Diamond : public Derived1, public Derived2
{

};

int main()
{
    Diamond diamond;
    diamond.value = 5;
    return 0;
}
