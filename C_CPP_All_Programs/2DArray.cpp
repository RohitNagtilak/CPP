#include <iostream>
using namespace std;
int main()
{
    int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int * ptr;
    ptr = *arr;
    cout << "\nUsing ptr :" << endl;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << i << "x" << j << " -- " << *ptr << "\t";
            ptr++;
        }
        cout << endl;
    }
    cout << "\nUsing ar :" << endl;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << i << "x" << j << " -- " << arr[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
