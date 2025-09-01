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
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr[9];
    for (int i = 0; i != ivec.size(); ++i)
    {
        arr[i] = ivec[i];
    }

    for (auto num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}