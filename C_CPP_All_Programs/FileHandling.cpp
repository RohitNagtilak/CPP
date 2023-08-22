#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
	//string str;

	ofstream out;
	out.open("text1.txt");
	if (!out.is_open())
	{
		cout << "\n Cannot open file";
		exit(0);
	}

	//writing string
	//str="rohit";
	//out.write(str, 10);


	for (int i = 65; i <= 90; i++)
		out.put(static_cast<char>(i));

	cout << "\n Writing data to File is Done...!";
	out.close();

	//-------------

	ifstream in;
	in.open("text1.txt");
	if (!in.is_open())
	{
		cout << "\n Cannot open File";
		exit(0);
	}

	/*while (!in.fail())
	{
		in.read(str, 20);
		if (in.eof())
			break;
		cout << " " << str;
	}*/

	char ch;
	while ((ch = in.get()) != EOF)
		cout << " " << ch;

	in.close();
	return 0;
}