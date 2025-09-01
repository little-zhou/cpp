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
    vector<int> ivec;
    for (int num = 0; cin >> num; ivec.push_back(num))
        ;

    for (auto it = ivec.begin(); it != ivec.end() -1; ++it)
    {
        cout << *it + *(it + 1) << " ";
    }
    return 0;
}