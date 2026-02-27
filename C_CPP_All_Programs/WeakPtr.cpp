#include <iostream>
using namespace std;

int main()
{
    auto sharedPtr = make_shared<int>(100);

    // create a weak_ptr observing the same object (does NOT increase shared use_count)
    weak_ptr<int> weakPtr(sharedPtr);

    // shared_ptr UseCount = number of shared owners (here 1)
    cout << "shared_ptr UseCount = " << sharedPtr.use_count() << endl;

    // weak_ptr.use_count() returns the number of shared owners (same as sharedPtr.use_count())
    // Note: constructing a weak_ptr does NOT increment the shared owners count.
    cout << "Weak_ptr UseCount = " << weakPtr.use_count() << endl;

    // weak_ptr.expired() returns true if the managed object has been destroyed
    // or if the weak_ptr is empty (i.e., no associated control block or no shared owners).
    cout << "Weak_ptr.expired() = " << weakPtr.expired() << endl << endl;

    // lock() tries to acquire a shared_ptr from the weak_ptr.
    // If the object is still alive, lock() returns a non-empty shared_ptr and increments use_count().
    // If the object has been destroyed (or weak_ptr is empty), lock() returns an empty shared_ptr.
    if (shared_ptr<int> shPtr = weakPtr.lock())
    {
        cout << "*shPtr = " << *shPtr << endl;
        // use_count increases because shPtr is now an additional shared owner in this scope
        cout << "shared_ptr UseCount = " << sharedPtr.use_count() << endl;
    }
    else
    {
        cout << "Resource Not Found..!" << endl;
    }

    // reset() makes weakPtr empty (it no longer observes the control block)
    weakPtr.reset();

    // After reset, weakPtr.lock() will return an empty shared_ptr (lock fails).
    // Also weakPtr.expired() would be true because weak_ptr no longer refers to an object.
    if (shared_ptr<int> shPtr = weakPtr.lock())
    {
        cout << "*shPtr = " << *shPtr << endl;
        cout << "shared_ptr UseCount = " << sharedPtr.use_count() << endl;
    }
    else
    {
        cout << "Resource Not Found..!" << endl;
    }

    return 0;
}