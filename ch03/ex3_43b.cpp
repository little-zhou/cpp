#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cstring>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    for (size_t i = 0; i != 3; ++i)
    {
        for (size_t j = 0; j != 4; ++j)
        {
            cout << ia[i][j] << " ";
        }
    }

    cout << endl;
    return 0;
}