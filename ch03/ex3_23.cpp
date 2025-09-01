#include <vector>
#include <iterator>
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = ivec.begin(); it != ivec.end(); ++it)
    {
        *it *= (*it);
    }

    for (auto i : ivec)
    {
        cout << i << " ";
    }
    return 0;
}