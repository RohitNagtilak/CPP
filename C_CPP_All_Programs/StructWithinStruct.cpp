#include<iostream>
using namespace std;

struct  Date
{
	int dd{ 0 };
	int mm{ 0 };
	int yy{ 0 };
};

struct Student
{
	Date dob;
	string name{""};
	void display()
	{
		cout << " Name " << name << " " <<"Dob DD/MM/YY: "<<dob.dd<<"/"<<dob.mm<<"/"<<dob.yy<<endl;
	}
};

int main()
{
	Student std;
	std.dob.dd = 9;
	std.dob.mm = 12;
	std.dob.yy = 1998;
	std.name = "Rohit";
	std.display();

}