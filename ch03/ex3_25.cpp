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
    unsigned scores[11] = {};
    for (unsigned grade; cin >> grade;)
    {
        if (grade <= 100)
        {
            ++scores[grade / 10];
        }
    }

    for (auto i : scores)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}