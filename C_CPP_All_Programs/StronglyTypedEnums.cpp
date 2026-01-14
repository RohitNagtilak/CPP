/*
    Strongly-Typed Enums (enum class) – C++11:
    Old enums are weakly typed, leak names into the global scope, and allow implicit int conversions.
    enum class fixes these issues by providing strong typing, scoped names, and explicit conversions.
    This improves compile-time safety and avoids name collisions in large codebases.
*/

#include <iostream>
using namespace std;

// Old enum (problematic)
enum OldColor { Red, Green, Blue };

// Strongly-typed enum
enum class Color : int 
{
    Red = 1,
    Green = 2,
    Blue = 3
};

int main() 
{
    OldColor oc = Red;     // names leak into global scope
    int x = oc;            // implicit conversion allowed (unsafe)

    Color c = Color::Green;
    // int y = c;           // ❌ not allowed (strong typing)

    int y = static_cast<int>(c);  // explicit conversion
    cout << "Color value = " << y << endl;

    return 0;
}
