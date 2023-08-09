/*
	- Using std::string in a union can lead to problems because
	  std::string is a complex object that manages its own memory dynamically.
	- When a union contains a std::string, it may not properly handle the memory
	  allocation, deallocation, and object construction/destruction. 
	- This can result in undefined behavior and lead to program crashes, memory
	  leaks, or other issues.
*/

#include<iostream>
using namespace std;

union Student
{
	string *name = NULL;
	int age;
};

int main()
{
    Student s;
    s.age = 10;
	cout << "Age of student is : " << s.age<<endl;

    s.name = new string("Rohit");
	cout << "Name of student is : " << *(s.name)<<endl;
	delete s.name;
	
	return 0;
}
