#include <iostream>

// Template function to find the maximum of two values
template <typename T>
T findMax(T a, T b)
{
    return (a > b) ? a : b;
}

int main() {
    int maxInt = findMax<int>(5, 10);
    double maxDouble = findMax<double>(3.14, 2.71);

    std::cout << "Max integer: " << maxInt << std::endl;
    std::cout << "Max double: " << maxDouble << std::endl;

    return 0;
}
