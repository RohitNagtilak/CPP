/*
long long (long long int):
long long is an integer type that provides at least 64-bit signed storage.
It is used when values exceed the range of int and long (e.g., large counts, timestamps).
Range is guaranteed to be at least −2^63 to 2^63−1 on all modern compilers.
*/

#include <iostream>
#include <climits>
using namespace std;

int main() 
{
    long long a = 9223372036854775807LL;   // maximum value
    long long b = -9223372036854775807LL;  // large negative value

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "Size of long long = " << sizeof(long long) << " bytes\n";
    cout << "LLONG_MAX = " << LLONG_MAX << endl;
    cout << "LLONG_MIN = " << LLONG_MIN << endl;

    return 0;
}
