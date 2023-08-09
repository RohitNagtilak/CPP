#include<iostream>
using namespace std;

class Simple
{
public:
	int* data;
	int i;
};

int main()
{
	Simple p;
	p.data = new int(10);
	p.i = 20;
	cout << "P -> Data= " << *(p.data) << " i= " << p.i<<endl;

	Simple q(p);
	cout << "Q -> Data= " << *(q.data) << " i= " << q.i<<endl;

	*(q.data) = 30;
	cout << "P -> Data= " << *(p.data) << " i= " << p.i << endl;
	cout << "Q -> Data= " << *(q.data) << " i= " << q.i<<endl;
	return 0;
}