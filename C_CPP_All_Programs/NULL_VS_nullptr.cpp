/* 
Why is NULL Ambiguous?
•	NULL is typically defined as 0 (an integer constant).
•	When calling overloaded functions that accept both an integer and a pointer, passing NULL can confuse the compiler, as it matches both signatures.
•	This can lead to compilation errors or unexpected behavior.

Why is nullptr Not Ambiguous ?
•	nullptr (introduced in C++11) is a keyword representing a null pointer constant.
•	It has its own type(std::nullptr_t) and only matches pointer overloads, not integers.
•	This removes ambiguity and makes code safer and clearer. 
*/

#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
};

void func(int n) 
{
    cout << "Called func(int)" << endl;
}

void func(Node* ptr) 
{
    cout << "Called func(Node*)" << endl;
}

int main() 
{
    func(NULL);    // Error: ambiguous call in C++11 and later
    func(nullptr);    // Calls func(Node*), unambiguous

    return 0;
}