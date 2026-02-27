#include <iostream>
#include <memory>

class Base
{
public:
    Base()
    {
        std::cout << "Base constructor" << std::endl;
    }

    Base(int parameter)
    {
        std::cout << "Base constructor: " << parameter << std::endl;
    }
};

class LeafA : public virtual Base
{
public:
    Base member; // member object of type Base

    LeafA()
    {
        std::cout << "LeafA constructor" << std::endl;
    }

    LeafA(int parameter)
        : Base(parameter)  // calls Base constructor for the virtual Base
    {
        std::cout << "LeafA constructor: " << parameter << std::endl;
    }
};

class LeafB : public virtual Base
{
public:
    Base member;

    LeafB()
    {
        std::cout << "LeafB constructor" << std::endl;
    }

    LeafB(int parameter)
        : Base(parameter)
    {
        std::cout << "LeafB constructor: " << parameter << std::endl;
    }
};

class Child : public LeafA, public LeafB
{
public:
    Child()
    {
        std::cout << "Child constructor" << std::endl;
    }

    Child(int parameter)
        : Base(parameter), LeafA(parameter), LeafB(parameter) // Base must be initialized first
    {
        std::cout << "Child constructor: " << parameter << std::endl;
    }
};

int main()
{
    auto var2 = std::make_unique<Child>(15);

    return 0;
}
