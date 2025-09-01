#include <iostream>
#include <vector>
#include <iterator>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::vector;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto *it = begin(arr); it != end(arr); ++it)
    {
        *it = 0;
    }

    for (auto num : arr)
        cout << num << " ";

    cout << endl;
    return 0;
}