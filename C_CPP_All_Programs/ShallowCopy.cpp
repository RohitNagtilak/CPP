#include<iostream>
using namespace std;

class Test
{
public:
	int* data;
};

int main()
{
	Test p;
	p.data = new int(10);
	cout << "P -> Data= " << *(p.data) <<endl;

	Test q(p);
	cout << "Q -> Data= " << *(q.data) <<endl;

	*(q.data) = 30;
	cout << "P -> Data= " << *(p.data) << endl;
	cout << "Q -> Data= " << *(q.data) <<endl;
	return 0;
}