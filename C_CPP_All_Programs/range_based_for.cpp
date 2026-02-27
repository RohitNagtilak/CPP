// range_based_for_examples.cpp
#include <iostream>
#include <vector>
#include <array>
#include <map>
using namespace std;

int main()
{

    // 1. Vector – basic range-based for
        vector<int> v = { 1, 2, 3, 4 };
        cout << "Vector (copy values): ";
        for (int x : v) 
        {          // copies each element
            cout << x << " ";
        }
        cout << "\n";

    // 2. Vector – modify elements using reference
        cout << "Vector (modified by reference): ";
        for (int& x : v) 
        {         // reference → no copy, allows modification
            x *= 2;
        }
        
        for (int x : v) 
        {
            cout << x << " ";
        }
        cout << "\n";

    // 3. Vector – const reference, no modify
        cout << "Vector (const reference): ";
        for (const int& x : v) 
        {   // no copy, safe for read-only
            cout << x << " ";
        }
        cout << "\n";

    // 4. Using auto (recommended)
    // auto deduces exact type → safer + avoids narrowing + avoids long type names
        cout << "Vector (auto): ";
        for (auto& x : v) {        // auto& → avoids copying, efficient for big objects
            x += 5;
        }
        for (auto x : v) {         // auto → correct type deduced
            cout << x << " ";
        }
        cout << "\n";

    // 5. Raw Array example
    int arr[] = { 10, 20, 30 };
    cout << "Raw array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";

    // 6. std::array example
    array<int, 3> a = { 100, 200, 300 };
    cout << "std::array: ";
    for (auto x : a)
    {         // auto works perfectly here too
        cout << x << " ";
    }
    cout << "\n";

    // 7. Map with range-based for
    map<string, int> m = { {"apple", 3}, {"banana", 5}, {"mango", 2} };
    cout << "Map (key-value):\n";
    for (const auto& p : m) {  // auto avoids typing pair<const string, int>
        cout << p.first << ": " << p.second << "\n";
    }

    // 8. C++17 structured bindings with map
    cout << "Map (structured bindings):\n";
    for (const auto& [key, value] : m) 
    { 
        // auto deduces pair element types
        cout << key << ": " << value << "\n";
    }

    return 0;
}
