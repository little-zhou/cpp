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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ivec(begin(arr), end(arr));
    for (auto i : ivec)
        cout << i << " ";
    cout << endl;
    return 0;
}