#include <iostream>
using namespace std;

// Generic template: works for any type T
template<typename T>
T square(T x)
{
    cout << "Generic template called \n";
    return x * x;
}

// Option 1: Normal function for bool (no template<>)
// This is NOT a specialization; it's a separate function
bool square(bool x) 
{
    cout << "Normal function for bool called \n";
    return x; // optimized for bool
}

// Option 2: Template specialization for bool
/*
template<>
bool square(bool x) {
    cout << "Specialized template for bool called\n";
    return x; // optimized for bool
}
*/

int main() 
{
    int a = 5;
    bool b = true;

    // Calls generic template
    cout << "square(a): " << square(a) << endl;

    // Calls normal function for bool
    cout << "square(b): " << square(b) << endl;

    // Uncomment the specialized template above and comment the normal function:
    // Now, square(b) will call the specialized template instead of the normal function
}
