#include <iostream>

void f(int a, int b)
{
    std::cout << "a = " << a << ", b = " << b << '\n';
}

int main()
{
    int i = 0;
    f(i++, i++);
}
