#include <iostream>
#include <string>
using namespace std;

void Display(int number)
{
    if (number == 0)
        throw 0;
    else if (number > 0)
        throw "some inappropriate value";
    else
        throw '\n';
}

int main()
{
    int integerInput, operation;
    char charInput;

    try 
    {
        cout << "\n Enter 1 for integer or 0 for char: ";
        cin >> operation;

        if (operation == 1) 
        {
            cout << "Enter an integer: ";
            cin >> integerInput;
            Display(integerInput);
        }
        else 
        {
            cout << "Enter a char: ";
            cin >> charInput;
            Display(charInput);
        }
    }
    catch (int ex) 
    {
        cout << "\n EXCEPTION: Wrong Integer";
    }
    catch (char* ex) 
    {
        cout << "\n EXCEPTION: Wrong Char";
    }
    catch (...)
    {
        cout << "\n EXCEPTION: Wrong Data";
    }

    return 0;
}
