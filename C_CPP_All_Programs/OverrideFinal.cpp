/*
override & final – C++11:
override ensures a virtual function correctly overrides a base class function, catching mistakes at compile time.
final prevents further overriding of a virtual function or inheritance of a class.
They improve safety, readability, and maintainability in polymorphic code.
*/

#include <iostream>
using namespace std;

class Base 
{
public:
    virtual void show() {
        cout << "Base show\n";
    }

    virtual void process() final {   // cannot be overridden
        cout << "Base process\n";
    }
};

class Derived : public Base 
{
public:
    void show() override 
    {            // guaranteed override
        cout << "Derived show\n";
    }

    // void process() override {      // ❌ ERROR: function is final
    // }
};

// class Child final : public Base {  // class cannot be inherited further
// };

int main()
{
    Base* b = new Derived();
    b->show();        // calls Derived::show (runtime polymorphism)
    b->process();     // calls Base::process

    delete b;
    return 0;
}
