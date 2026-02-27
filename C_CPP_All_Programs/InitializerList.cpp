/*
Advantages of constructor initializer lists:
- Direct initialization of members: members are constructed directly with the provided values,
  avoiding default construction followed by assignment (more efficient).
- Required for certain members:
    - const members
    - reference members
    - members of types without a default constructor
- Guarantees the initialization order follows the order of member declaration in the class,
  which helps avoid subtle bugs when one member depends on another.
- Enables initialization of base classes and member objects with parameters.
- Often results in clearer intent and potentially better-optimized code by the compiler.
*/

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    // Constructor uses an initializer list to initialize `name` and `age`.
    // This constructs `name` directly from the incoming string and initializes `age`
    // without first default-constructing them then assigning.
    Person(const std::string& name, int age)
        : name(name)  // initialize `name` directly
        , age(age)    // initialize `age` directly
    {
        // Constructor body is empty because all initialization is done above.
    }

private:
    // Note: members are initialized in the order they are declared here,
    // regardless of the order in the initializer list.
    string name;
    int age;
};


int main()
{
    // Use the constructor with initializer list to create a Person.
    Person p("Rohit", 24);

    // Program does nothing else; return success.
    return 0;
    }