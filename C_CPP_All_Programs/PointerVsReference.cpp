/*
    A pointer stores the memory address of a variable, while a reference acts as an alias to the same memory location.
    Pointers can be reassigned to point to another address, but a reference cannot be reassigned once initialized.
    Pointers can hold a null value, whereas references cannot be null.
    Pointer arithmetic operations are allowed, but arithmetic on references is not permitted.
    Pointers require indirection (dereferencing) using *, while references are accessed directly like normal variables.
*/
#include <iostream>
using namespace std;

int main() 
{
    int a = 10;
    int b = 20;

    // =========================
    // POINTER DEMONSTRATION
    // =========================

    int* p = &a;   // Pointer stores memory address of 'a'

    cout << "Pointer p address : " << p << endl;
    cout << "Value via pointer : " << *p << endl; // Indirection (dereferencing)

    p = &b;        // Pointer can be reassigned
    cout << "After reassignment, p points to b : " << *p << endl;

    int* nullPtr = nullptr; // Pointer can be null
    cout << "Null pointer value : " << nullPtr << endl;

    // Pointer arithmetic
    int arr[3] = { 1, 2, 3 };
    int* arrPtr = arr;
    cout << "Pointer arithmetic *(arrPtr + 1): " << *(arrPtr + 1) << endl;

    // =========================
    // REFERENCE DEMONSTRATION
    // =========================

    int& ref = a;  // Reference must be initialized, alias of 'a'

    cout << "Reference value : " << ref << endl;
    cout << "Reference address : " << &ref << endl; // Same as address of 'a'

    // ref = &b;   // ❌ ERROR: Reference cannot be reassigned
    ref = b;       // Assigns value of b to a (NOT rebinding)

    cout << "After ref = b, a value : " << a << endl;

    // int& nullRef = nullptr; // ❌ ERROR: Reference cannot be null

    // No pointer arithmetic on reference
    // ref++; // changes value, not address

    return 0;
}
