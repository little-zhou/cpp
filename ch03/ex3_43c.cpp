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

    for (int (*row)[4] = ia; row != ia + 3; ++row)
    {
        for (int *col = *row; col != *row + 4; ++col)
        {
            cout << *col << " ";
        }
    }
    cout << endl;

    return 0;
}