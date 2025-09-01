#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cstring>
#include <typeinfo>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int &i : ivec)
    {
        if (i & 0x1)
        {
            i *= 2;
        }
    }

    for (auto i : ivec)
        cout << i << " ";
    cout << endl;
    return 0;
}