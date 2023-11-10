#include <iostream>
#include <cstdlib> // For malloc, calloc, realloc functions
using namespace std;

int main()
{
    // Using malloc to allocate memory for an array of integers
    int n;
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

    // Using realloc to resize the memory block allocated with malloc
    int m;
    cout << "Enter the new size for reallocation: ";
    cin >> m;

    int* arr3 = (int*)realloc(arr1, m * sizeof(int));
    if (arr3 == nullptr)
    {
        cout << "Memory reallocation using realloc failed!" << endl;
        free(arr1); // Free the original memory block
        return 1;
    }
    for (int i = n; i < m; i++)
        arr3[i] = i + 1;

    cout << "Memory reallocated using realloc:" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;

    // Freeing allocated memory
    free(arr3);

    return 0;
}
