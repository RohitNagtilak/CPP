#include<iostream>
#include<thread>
using namespace std;
void DisplayNumber()
{
	for (int i = 0; i < 26; i++)
		cout << " " << i <<endl ;
}

void DisplayLetters()
{
	for (char i = 'A'; i <='Z'; i++)
		cout << " " << i << endl;
}

int main()
{
	thread t1(DisplayNumber);
	thread t2(DisplayLetters);

	t1.join();
	t2.join();

	return 0;
}