#include<iostream>
#include<cstring>
using namespace std;
class MyString
{
public:
	MyString():str(nullptr){}

	MyString(const char* str)
	{
		if (str != nullptr)
		{
			this->str = new char[strlen(str) + 1];
			strcpy_s(this->str, strlen(str) + 1, str);
		}
		else
			this->str = nullptr;
	}
	
	MyString& operator=(const MyString& obj)
	{
		if (this == &obj)	//Self-assignment check
			return *this;
		
		delete[] this->str;

		if (obj.str != nullptr)
		{
			this->str = new char[strlen(obj.str) + 1];
			strcpy_s(this->str, strlen(obj.str) + 1, obj.str);
		}
		else
			this->str = nullptr;

		return *this;
	}

	MyString(const MyString& obj)
	{
		if (obj.str != nullptr)
		{
			this->str = new char[strlen(obj.str) + 1];
			strcpy_s(this->str, strlen(str) + 1, obj.str);
		}
		else
			this->str = nullptr;
	}

	~MyString()
	{
		delete[] this->str;
	}

private:
	char* str;
};

int main()
{
	MyString a = "abc";
	MyString b = a;
	MyString c;
	c = b;

	return 0;
}