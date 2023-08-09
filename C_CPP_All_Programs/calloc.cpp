#include <iostream>
#include <cstdlib> // For malloc, calloc, realloc functions
using namespace std;

int main()
{
    int n;
    // Using malloc to allocate memory for an array of integers
    cout << "Enter the number of elements: ";
    cin >> n;

    // Using calloc to allocate memory for an array of integers
    int* arr = (int*)calloc(n, sizeof(int));
    if (arr == nullptr)
    {
        cout << "Memory allocation using calloc failed!" << endl;
        return 1;
    }

    cout << "Memory allocated using calloc:" << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = (i + 1) * 10;
        cout << arr[i] << " ";
    }
    cout << endl;
    free(arr);

    return 0;
}