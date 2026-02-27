#include <iostream>
#include <stdexcept>
using namespace std;

class A 
{
    int* data;
public:
    A() 
    {
        cout << "Constructor called\n";
        data = new int[5];       // manual allocation
        throw runtime_error("Error in constructor!"); // exception thrown
    }
    ~A() 
    {
        cout << "Destructor called\n";
        delete[] data;           // NOT called here
    }
};

int main() 
{
    try 
    {
        A obj; // exception occurs
    }
    catch (const runtime_error& e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
}

//
//class A 
// {
//    unique_ptr<int[]> data; // RAII: smart pointer automatically frees memory
//public:
//    A() 
//    {
//        cout << "Constructor called\n";
//        data = make_unique<int[]>(5); // memory allocated safely
//        throw runtime_error("Error in constructor!"); // exception thrown
//    }
//
//    ~A() 
//    {
//        cout << "Destructor called\n";
//        // No need to delete data, unique_ptr cleans it automatically
//    }
//};
//
//int main() 
// {
//    try 
//    {
//        A obj; // Exception occurs here
//    }
//    catch (const runtime_error& e) 
//    {
//        cout << "Caught exception: " << e.what() << endl;
//    }
//}
//

//What Happens
//
//Constructor starts → allocates memory for data.
//Exception is thrown → constructor stops immediately.
//Destructor is NOT called → delete[] data is skipped → memory leak occurs.
//If you use a smart pointer instead of new, memory is automatically freed, no leak.
//

//What Happens Here
//
//Constructor allocates memory with unique_ptr.
//Exception is thrown.
//Destructor is not called, but unique_ptr automatically frees memory → no memory leak.
//
