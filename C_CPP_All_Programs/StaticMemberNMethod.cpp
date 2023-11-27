#include <iostream>
using namespace std;

class MyClass
{
public:
    static int staticDataMember;
    static void staticMemberFunction()
    {
        cout << "Inside static member function\n";
    }
};

int MyClass::staticDataMember = 0;

int main()
{
    MyClass::staticMemberFunction();
    MyClass::staticDataMember = 5;
    cout << "Value of staticDataMember: " << MyClass::staticDataMember << endl;
    return 0;
}