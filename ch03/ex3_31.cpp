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
    for (size_t i = 0; i < array_size; ++i)
    {
        ia[i] = i;
    }

    for (auto num : ia)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}