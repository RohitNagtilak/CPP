#include <iostream>
using namespace std;
int main()
{
    int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    /*int* ptr;
    ptr = &arr[0][0];*/

    //Way-1
    int* ptr = &arr[0][0];
    cout << "\nUsing Pointer :" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << *ptr << "\t";
            ptr++;
        }
        cout << endl;
    }
    //Way-2
    cout << "\nUsing Array Index :" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << arr[i][j] << "\t";
        }
        cout << endl;
    }
    //Way-3
    ptr = &arr[0][0];
    cout << "Using Size :" << endl;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0][0])); i++)
    {
        cout << " " << *ptr;
        ptr++;
    }


    return 0;
}