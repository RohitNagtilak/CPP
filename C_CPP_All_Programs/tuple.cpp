#include <iostream>
#include <tuple>

using namespace std;

int main()
{
    // std::tuple
    // Stored as a fixed-size heterogeneous object (no single DS, implemented via template composition).
    // Use when you need to group multiple values of different types without defining a struct.
    tuple<int, double, string> t{ 1, 3.14, "Hello" };

    cout << get<0>(t) << endl;
    cout << get<1>(t) << endl;
    cout << get<2>(t) << endl;

    return 0;
}
