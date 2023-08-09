#include <iostream>
#include <cstdlib> // For malloc, calloc, realloc functions
using namespace std;

int main()
{
    int n;
    // Using malloc to allocate memory for an array of integers
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr1 = (int*)malloc(n * sizeof(int));
    if (arr1 == nullptr) 
    {
        cout << "Memory allocation using malloc failed!" << endl;
        return 1;
    }

    cout << "Memory allocated using malloc:" << endl;
    for (int i = 0; i < n; i++)
    {
        arr1[i] = i + 1;
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Freeing allocated memory
    free(arr1);

    return 0;
}