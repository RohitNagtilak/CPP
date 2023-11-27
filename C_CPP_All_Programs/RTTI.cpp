#include <iostream>
#include <typeinfo>

class Base 
{
public:
    virtual ~Base() {} // Ensuring a polymorphic base class
};

class Derived : public Base 
{
    // Some class definition
};

int main() 
{
    Base* basePtr = new Derived();

    // dynamic_cast operator example
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr != nullptr)
    {
        std::cout << "Dynamic cast successful. Pointer cast to Derived." << std::endl;
    }
    else 
    {
        std::cout << "Dynamic cast failed. Pointer cannot be cast to Derived." << std::endl;
    }

    // typeid Operator example
    const std::type_info& typeInfo = typeid(*basePtr);
    std::cout << "Object type using typeid: " << typeInfo.name() << std::endl;

    // type_info Class example
    Base* anotherBasePtr = new Derived();
    const std::type_info& typeInfo1 = typeid(*basePtr);
    const std::type_info& typeInfo2 = typeid(*anotherBasePtr);

    if (typeInfo1 == typeInfo2)
    {
        std::cout << "Both pointers point to the same type." << std::endl;
    }
    else 
    {
        std::cout << "Pointers point to different types." << std::endl;
    }

    delete basePtr;
    delete anotherBasePtr;
    return 0;
}
