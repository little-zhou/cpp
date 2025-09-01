#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include <cstddef>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 1; ix <= array_size; ++ix)
        ia[ix] = ix;

    for (auto i : ia)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
