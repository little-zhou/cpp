#include <iostream>
#include <vector>
#include <iterator>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::vector;

bool compare(int *const pb1, int *const pe1, int *const pb2, int *const pe2)
{
    if ((pe1 - pb1) != (pe2 - pb2))
    {
        return false;
    }
    else
    {
        for (int *i = pb1, *j = pb2; (i != pe1) && (j != pe2); ++i, ++j)
        {
            if (*i != *j)
                return false;
        }
        return true;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};

    if (compare(arr, end(arr), arr2, end(arr2)))
        cout << "The two arrays are equal." << endl;
    else
        cout << "The two arrays are not equal." << endl;

    vector<int> ivec1 = {1, 2, 3, 4, 5};
    vector<int> ivec2 = {1, 2, 3, 4, 5};

    if (ivec1 == ivec2)
        cout << "The two vectors are equal." << endl;
    else
        cout << "The two vectors are not equal." << endl;

    return 0;
}