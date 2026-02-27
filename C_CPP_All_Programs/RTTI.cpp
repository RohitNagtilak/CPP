#include <iostream>
#include <typeinfo>
//RTTI (Run‑Time Type Information) in C++ is the language facility that lets you inspect and safely convert object types at runtime. It powers the dynamic_cast operator and the typeid operator.
// Polymorphic base class (has a virtual destructor so RTTI works correctly)
class Base
{
public:
    virtual ~Base() {} // ensures `typeid(*ptr)` and `dynamic_cast` work on Base pointers
};

class Derived : public Base
{
    // Derived-specific members would go here
};

int main()
{
    // Create a Base pointer that actually points to a Derived instance
    Base* basePtr = new Derived();

    // -------------------------
    // Example: dynamic_cast
    // -------------------------
    // dynamic_cast attempts a safe downcast from Base* to Derived*.
    // If `basePtr` actually points to a Derived object, the cast returns a non-null pointer.
    // If not, it returns nullptr (for pointer casts).
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr != nullptr)
    {
        std::cout << "Dynamic cast successful. Pointer cast to Derived." << std::endl;
    }
    else
    {
        std::cout << "Dynamic cast failed. Pointer cannot be cast to Derived." << std::endl;
    }

    // -------------------------
    // Example: typeid operator
    // -------------------------
    // `typeid(*basePtr)` yields the dynamic type of the object pointed to (requires polymorphic type).
    // The returned `std::type_info` contains runtime type information (implementation-defined name).
    const std::type_info& typeInfo = typeid(*basePtr);
    std::cout << "Object type using typeid: " << typeInfo.name() << std::endl;

    // -------------------------
    // Example: comparing type_info objects
    // -------------------------
    // Create another Base pointer to a Derived instance and compare their runtime types.
    Base* anotherBasePtr = new Derived();
    const std::type_info& typeInfo1 = typeid(*basePtr);        // dynamic type of first object
    const std::type_info& typeInfo2 = typeid(*anotherBasePtr); // dynamic type of second object

    if (typeInfo1 == typeInfo2)
    {
        // When both objects are of the same runtime type, the type_info objects compare equal.
        std::cout << "Both pointers point to the same type." << std::endl;
    }
    else
    {
        std::cout << "Pointers point to different types." << std::endl;
    }

    // Clean up heap-allocated objects
    delete basePtr;
    delete anotherBasePtr;

    return 0;
}
