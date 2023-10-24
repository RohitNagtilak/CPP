#include <iostream>

class Animal 
{
public:
    virtual void speak() {
        std::cout << "Animal speaks." << std::endl;
    }
};

class Dog : public Animal
{
public:
    void speak() override
    {
        std::cout << "Dog barks." << std::endl;
    }
};

int main()
{
    Animal* animal = new Dog();
    // Upcasting: Converting a Dog pointer to an Animal pointer
    animal->speak(); // Calls the Dog's speak method

    // Attempting downcasting using dynamic_cast
    Dog* dog = dynamic_cast<Dog*>(animal);
    if (dog)
    {
        std::cout << "Downcasting successful:" << std::endl;
    }
    else
    {
        std::cout << "Downcasting failed." << std::endl;
    }
    delete animal;
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