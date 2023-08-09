#include<iostream>
using namespace std;

class Person {
public:
    Person(const std::string& name, int age) 
        : name(name), age(age) 
    {
    }

private:
    std::string name;
    int age;
};


int main()
{
    Person p("Rohit", 24);

	return 0;
}