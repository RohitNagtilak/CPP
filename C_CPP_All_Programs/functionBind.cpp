#include <iostream>
#include <functional>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    // std::function
    // Stored as a type-erased callable wrapper (internally uses dynamic allocation / small object optimization).
    // Use when you need to store or pass functions, lambdas, or function objects with a uniform type.
    function<int(int, int)> func = add;
    cout << "Result: " << func(2, 3) << endl;

    // std::bind
    // Stored as a callable object that binds arguments to a function (uses templates to store state).
    // Use when you want to fix some arguments of a function and get a new callable.
    auto boundFunc = bind(add, 5, placeholders::_1); // first arg = 5, second arg to be provided later
    cout << "Bound Result: " << boundFunc(10) << endl;

    return 0;
}
