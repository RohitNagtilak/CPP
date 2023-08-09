#include<iostream>
using namespace std;
void Add()
{
    int x, y, result;
    try
    {
        x = 10;
        y = 0;
        if (y == 0)
        {
            throw std::runtime_error("Division by zero is not allowed.\n");
        }
        result = x / y;
    }
    catch (const std::exception& ex)
    {
        cout << "\nException Occurred: " << ex.what();
        return; // Return early to prevent further undefined behavior.
    }
    cout << " Result = " << result<<endl;
}

int main()
{
	Add();

	return 0;
}