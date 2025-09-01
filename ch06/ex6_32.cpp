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

int &get(int *arry, int index)
{
    return arry[index];
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int &res = get(arr, 3);

    cout << res << endl;
    return 0;
}