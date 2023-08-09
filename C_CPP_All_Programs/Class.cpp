#include <iostream>

// Template class for a generic Pair
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(const T1& f, const T2& s) : first(f), second(s) {}

    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    void display() const {
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }
};

int main() {
    // Creating a Pair of integers
    Pair<int, int> p1(1, 2);
    p1.display();

    // Creating a Pair of a character and a double
    Pair<char, double> p2('A', 3.14);
    p2.display();

    // Creating a Pair of string and bool
    Pair<std::string, bool> p3("Hello", true);
    p3.display();

    return 0;
}
