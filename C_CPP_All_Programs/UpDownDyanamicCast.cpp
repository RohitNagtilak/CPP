//
#include<iostream>
using namespace std;
class Base 
{
public:
    virtual ~Base() {}
};

class Derived : public Base 
{
public:
    void print() 
    {
        std::cout << "Derived class" << std::endl;
    }
};

int main()
{
    //Downcasting (Derived to Base)
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr)
    {
        derivedPtr->print();
    }
    else
    {
        std::cout << "Downcast failed." << std::endl;
    }

    //Upcasting (Base to Derived)
    Base* basePtr1 = new Derived();
    Base* upcastPtr = dynamic_cast<Base*>(basePtr1);
    if (upcastPtr) 
    {
        // The upcast will always succeed
        std::cout << "Upcast succeeded." << std::endl;
    }
    return 0;
}


/*

When to Use dynamic_cast:
 Use dynamic_cast when you need to perform type checking during downcasting within an inheritance hierarchy.
 Use it when you want to check if a base pointer or reference points to a derived object.

When to Avoid dynamic_cast:
 Avoid using dynamic_cast when working with non-polymorphic classes, 
 as it requires the classes to have at least one virtual function to enable runtime type checking.

 */