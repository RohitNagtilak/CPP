#include<iostream>
using namespace std;
int main() 
{
    shared_ptr<int> ptr(new int(42));

    cout << *ptr << endl;
    cout << ptr.use_count() << endl; // Output: 1

    {
        shared_ptr<int> ptr2 = ptr; // Assign ptr to ptr2, incrementing the reference count

        cout << *ptr2 << endl; // Output: 42
        cout << ptr.use_count() << endl; // Output: 2
    } // ptr2 goes out of scope here

    cout << *ptr << endl; // Output: 42
    cout << ptr.use_count() << endl; // Output: 1


    shared_ptr<int> sharedInt = make_shared<int>(1000);
    cout << *sharedInt << endl; // Output: 1
    
    sharedInt.reset();
    cout<<"Count = "<<sharedInt.use_count();

    return 0;
}
