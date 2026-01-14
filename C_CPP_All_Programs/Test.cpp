/*
Unicode String Literals – C++11:
C++ supports Unicode string literals using prefixes: u8, u, U, and L.
They define the character encoding and size used to store string data.
This enables portable handling of UTF-8, UTF-16, UTF-32, and wide-character strings.
*/

#include <iostream>
using namespace std;

int main()
{
    const char* s1 = "Hello";           // narrow string (ASCII / implementation-defined)
    const char* s2 = u8"Hello 🌍";       // UTF-8 encoded string (char)
    const char16_t* s3 = u"Hello";           // UTF-16 string (char16_t)
    const char32_t* s4 = U"Hello";           // UTF-32 string (char32_t)
    const wchar_t* s5 = L"Hello";           // wide string (wchar_t)

    cout << s1 << endl;
    cout << s2 << endl;

    cout << "sizeof(char)     = " << sizeof(char) << endl;
    cout << "sizeof(char16_t) = " << sizeof(char16_t) << endl;
    cout << "sizeof(char32_t) = " << sizeof(char32_t) << endl;
    cout << "sizeof(wchar_t)  = " << sizeof(wchar_t) << endl;

    return 0;
}
