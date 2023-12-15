//
//A Singleton is a design pattern that ensures a class has only one instance and provides a global point of access to that instance.
//This pattern is commonly used when you want to restrict the instantiation of a class to a single object. 
//Singleton is widely used for logging, configuration settings, database connections,
//and other scenarios where having multiple instances would be undesirable.

#include <iostream>
using namespace std;
class Singleton
{
public:
    // Static method to access the instance
    static Singleton& getInstance()
    {
        // This is a C++11 thread-safe way to create a Singleton
        // The instance is created on the first call to getInstance()
        static Singleton instance;
        return instance;
    }

    // Delete the copy constructor and the assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Other public member functions
    void showMessage() 
    {
        cout << "Hello from Singleton!" << endl;
    }

private:
    // Private constructor to prevent instantiation from outside
    Singleton() {}
};

int main() 
{
    // To get the instance of the Singleton class, use getInstance()
    Singleton& singleton = Singleton::getInstance();

    // Use the Singleton object
    singleton.showMessage();

    return 0;
}