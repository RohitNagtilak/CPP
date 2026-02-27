#include <iostream>

class Parent
{
public:
    Parent()
    {
        std::cout << "Parent Constructor Called" << std::endl;
    }

    // Virtual destructor is required for polymorphic deletion
    virtual ~Parent()
    {
        std::cout << "Parent Destructor Called" << std::endl;
    }
};

class Child : public Parent
{
public:
    Child()
    {
        std::cout << "Child Constructor Called" << std::endl;
    }

    ~Child() override   // override is good practice
    {
        std::cout << "Child Destructor Called" << std::endl;
    }
};

int main()
{
    Parent* p = new Child();   // Base pointer to derived object
    delete p;                  // Correctly calls Child then Parent destructor
    return 0;
}