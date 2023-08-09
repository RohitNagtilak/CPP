#include<iostream>
using namespace std;
int main() 
{
    std::shared_ptr<int> ptr(new int(42));

    std::cout << *ptr << std::endl;
    std::cout << ptr.use_count() << std::endl; // Output: 1

    {
        std::shared_ptr<int> ptr2 = ptr; // Assign ptr to ptr2, incrementing the reference count

        std::cout << *ptr2 << std::endl; // Output: 42
        std::cout << ptr.use_count() << std::endl; // Output: 2
    } // ptr2 goes out of scope here

    std::cout << *ptr << std::endl; // Output: 42
    std::cout << ptr.use_count() << std::endl; // Output: 1


    std::shared_ptr<int> sharedInt = std::make_shared<int>(1000);
    std::cout << *sharedInt << std::endl; // Output: 1
    
    sharedInt.reset();
    cout<<"Count = "<<sharedInt.use_count();

    return 0;
}
