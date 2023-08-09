#include<iostream>
using namespace std;

class A
{
	weak_ptr<A> adj; //shared_ptr<A> adj;
public:
	A() { cout << "Constructor Called...!"<<endl; }
	~A() { cout << "Destructor Called...!"<<endl; }
	void setAdj(shared_ptr<A> ptr)
	{
		adj = ptr;
	}
};

int main()
{
	shared_ptr<A> ptr1(new A);
	shared_ptr<A> ptr2(new A);

	cout << "Use_Count of Ptr1 = " << ptr1.use_count()<<endl;
	cout << "Use_Count of Ptr2 = " << ptr2.use_count()<<endl;

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

			//Destructor will not be called.