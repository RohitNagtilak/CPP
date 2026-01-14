/*
Uniform Initialization (C++11):
Uses {} to initialize all types consistently (fundamental types, objects, containers).
It prevents narrowing conversions and prefers initializer_list constructors, making code safer and clearer.
*/

#include <iostream>
#include <vector>

class Point
{
public:
    int x, y;
    Point(int a, int b) : x{ a }, y{ b } {}   // constructor using uniform initialization
};

int main() 
{
    int a{ 10 };           // fundamental type initialization
    int zero{};          // zero-initialization (0)

    // int n{3.5};       // ❌ narrowing conversion – compile-time error

    Point p{ 1, 2 };       // object initialization using {}

    std::vector<int> v1{ 5 };        // initializer_list → {5}
    std::vector<int> v2(5);        // size constructor → {0,0,0,0,0}
    std::vector<int> v3{ 1, 2, 3 };  // list initialization

    std::cout << a << " " << zero << " " << p.x << "," << p.y << std::endl;
}