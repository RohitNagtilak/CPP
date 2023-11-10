#include<iostream>
using namespace std;

int* Number()
{
	int a = 10;
	return &a; // Returning the address of the local variable
}

int main()
{
//CASE_1
//Deallocation of memory.

	int* ptr=(int*)malloc(sizeof(int));
	*ptr = 10;
	//or
	int* ptr1 = new int; 
	*ptr1 = 20;

	// Pointers are now become a dangling pointer.
	free(ptr);
	delete ptr1;

	//Pointers are no longer danling pointers
	ptr = ptr1 = NULL;

	if (ptr != NULL && ptr1 != NULL)
	{
		cout << *ptr << endl;
		cout << *ptr1 << endl;
	}

//CASE_2
	//Returning local variable in function call.

	int* ptr2 = Number();
	cout << *ptr2<<endl; // Accessing a dangling pointer

//CASE_3 
	//Variable going out of scope
	int* pr;
	{
		int i = 30;
		pr = &i;
	}
	//Pointer is now dangling pointer
	cout << "*pr =" << *pr;

	return 0;
}