#include <iostream>

int main()
{
    int a = 20;
    int* b = nullptr;
    int** c = nullptr;

    b = &a;
    c = &b;

    std::cout << "*b = " << *b << '\n';                         // 20
    std::cout << "b = " << static_cast<void*>(b) << '\n';       // address of a
    std::cout << "&b = " << static_cast<void*>(&b) << '\n';     // address of b

    std::cout << "a = " << a << '\n';                           // 20
    std::cout << "&a = " << static_cast<void*>(&a) << '\n';     // address of a

    std::cout << "c = " << static_cast<void*>(c) << '\n';       // address of b
    std::cout << "*c = " << static_cast<void*>(*c) << '\n';     // address of a
    std::cout << "**c = " << **c << '\n';                       // 20

    return 0;
}