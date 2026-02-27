#include<iostream>
using namespace std;

class A
{
	weak_ptr<A> adj;
	//shared_ptr<A> adj;
public:

	A() { cout << "Constructor Called...!" << endl; }
	~A() { cout << "Destructor Called...!" << endl; }

	void setAdj(shared_ptr<A> ptr)
	{
		adj = ptr;
	}
};

int main()
{
	shared_ptr<A> ptr1 = make_shared<A>();
	shared_ptr<A> ptr2 = make_shared<A>();

	cout << "Use_Count of Ptr1 = " << ptr1.use_count() << endl;
	cout << "Use_Count of Ptr2 = " << ptr2.use_count() << endl;

	ptr1->setAdj(ptr2);
	ptr2->setAdj(ptr1);

	cout << "Use_Count of Ptr1 = " << ptr1.use_count() << endl;
	cout << "Use_Count of Ptr2 = " << ptr2.use_count() << endl;

	return 0;
}

//	obj1	------>Adj 	 	obj2
//			Adj <-------
//	 |						 |
//	 |						 |
//	ptr1					ptr2
//
// Destructor will not be called.
//
// Reason:
// - A reference cycle is created: each object holds a `shared_ptr` to the other.
// - After `ptr1` and `ptr2` go out of scope, the `adj` members still own the objects,
//   so both objects have a nonzero `use_count` and their destructors are never invoked.
//
// Use of `weak_ptr`:
// - `weak_ptr` is a non-owning observer: assigning a `weak_ptr` does NOT increase the
//   `use_count` of the managed object, so it breaks ownership cycles.
// - To access the object safely, call `adj.lock()` which returns a `shared_ptr`
//   if the object is still alive; check the result before dereferencing.
//
// Tips:
// - Replace `shared_ptr<A> adj;` with `weak_ptr<A> adj;` to break the cycle.
// - Prefer `make_shared<T>()` over `shared_ptr<T>(new T)` for efficiency and safety.