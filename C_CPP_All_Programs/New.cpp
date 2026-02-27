#include <iostream>
using namespace std;

int main()	
{
	// Allocate a single int on the heap and initialize it to 5
	int *value = new int(5);

	// Dereference the pointer to print the stored value
	cout << "Value = " << *value << endl;

	// Free the allocated memory to avoid a memory leak
	delete value;
	// After delete, `value` becomes a dangling pointer.
	// Consider setting it to nullptr if it will be used later:
	// value = nullptr;

	return 0;
}