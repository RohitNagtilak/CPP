#include<iostream>
#include<thread>
using namespace std;
void DiplayNumber()
{
	for (int i = 0; i < 26; i++)
		cout << " " << i <<endl ;
}

void DiplayLetters()
{
	for (char i = 'A'; i <='Z'; i++)
		cout << " " << i << endl;
}

int main()
{

	thread t1(DiplayNumber);
	thread t2(DiplayLetters);

	t1.join();
	t2.join();

	return 0;
}