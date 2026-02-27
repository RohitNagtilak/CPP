#include <iostream>
#include <array>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    // std::array
    // Stored contiguously (stack/inline), designed as a fixed-size array.
    // Use when size is known at compile time and fast indexed access is needed.
    array<int, 3> arr = { 1, 2, 3 };
    cout << arr[0] << endl;

    // std::forward_list
    // Stored non-contiguously in heap, designed as a singly linked list.
    // Use when frequent insert/delete at front is needed with minimal memory overhead.
    forward_list<int> flist = { 1, 2, 3 };
    flist.push_front(0);
    for (int x : flist)
        cout << x << " ";
    cout << endl;

    // std::unordered_map
    // Stored in buckets in heap, designed using a hash table (key–value pairs).
    // Use when fast average O(1) lookup by key is more important than ordering.
    unordered_map<int, string> umap;
    umap[1] = "One";
    umap[2] = "Two";
    cout << umap[1] << endl;

    // std::unordered_set
    // Stored in buckets in heap, designed using a hash table (unique keys).
    // Use when fast existence checking of unique elements is required.
    unordered_set<int> uset = { 10, 20, 30 };
    uset.insert(40);
    cout << (uset.count(20) ? "Found" : "Not Found") << endl;

    return 0;
}
