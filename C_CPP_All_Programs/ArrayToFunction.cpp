#include <iostream>
#include <array>
#include <vector>
using namespace std;

/*========================================================
  1️⃣ RAW ARRAY (Pointer + Size)  ❌ Legacy / Least Safe
========================================================*/
void DisplayRaw(int* arr, int size)
{
    cout << "\n[Raw Array]\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*========================================================
  2️⃣ std::array  ✅ Best for FIXED size arrays
========================================================*/
void DisplayStdArray(const array<int, 5>& arr)
{
    cout << "\n[std::array]\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

/*========================================================
  3️⃣ std::vector  ✅ Best for DYNAMIC size arrays
========================================================*/
void DisplayVector(const vector<int>& v)
{
    cout << "\n[std::vector]\n";
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

/*========================================================
  4️⃣ 2D ARRAY using Template Reference  ✅ Best for fixed 2D
========================================================*/
template<int ROW, int COL>
void Display2D(int(&arr)[ROW][COL])
{
    cout << "\n[2D Array - Template]\n";
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

/*========================================================
  5️⃣ 2D ARRAY using vector<vector<int>>  ✅ Dynamic 2D
========================================================*/
void Display2DVector(const vector<vector<int>>& mat)
{
    cout << "\n[2D Vector]\n";
    for (const auto& row : mat)
    {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }
}

/*========================================================
  MAIN FUNCTION
========================================================*/
int main()
{
    /*---------- Raw Dynamic Array ----------*/
    int size = 5;
    int* rawArr = new int[size] {1, 2, 3, 4, 5};
    DisplayRaw(rawArr, size);
    delete[] rawArr;   // ❌ manual memory management

    /*---------- std::array ----------*/
    array<int, 5> arr1 = { 10, 20, 30, 40, 50 };
    DisplayStdArray(arr1);

    /*---------- std::vector ----------*/
    vector<int> v = { 100, 200, 300, 400, 500 };
    DisplayVector(v);

    /*---------- 2D Fixed Array ----------*/
    int arr2D[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Display2D(arr2D);

    /*---------- 2D Dynamic Vector ----------*/
    vector<vector<int>> mat =
    {
        {11, 12, 13},
        {21, 22, 23},
        {31, 32, 33}
    };
    Display2DVector(mat);

    return 0;
}
