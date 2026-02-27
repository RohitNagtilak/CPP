#include <iostream>
using namespace std;

struct Vector 
{
    int* data;
    int size;

    // Default constructor
    Vector(int s = 0) : size(s)
    {
        if (size > 0) {
            data = new int[size];
        }
        else {
            data = nullptr;
        }
    }

    // Copy constructor (deep copy)
    Vector(const Vector& other) : size(other.size) 
    {
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        else {
            data = nullptr;
        }
        cout << "Copy constructor called\n";
    }

    // Assignment operator (deep copy)
    Vector& operator=(const Vector& other) 
    {
        if (this == &other) // self-assignment check
            return *this;

        // Free existing memory
        delete[] data;

        // Copy size and allocate new memory
        size = other.size;
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        else {
            data = nullptr;
        }

        cout << "Assignment operator called\n";
        return *this;
    }

    // Destructor
    ~Vector() {
        delete[] data; // free allocated memory
        cout << "Destructor called\n";
    }
};

int main()
{
    Vector v1(5);      // create vector of size 5
    for (int i = 0; i < 5; i++) v1.data[i] = i;

    Vector v2 = v1;    // copy constructor called
    Vector v3;
    v3 = v1;           // assignment operator called

    return 0;
}
