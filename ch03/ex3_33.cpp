#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    unsigned scores[11];

    for (auto i : scores)
        cout << i << " ";

    cout << endl;

    for (unsigned grade; cin >> grade;)
    {
        if (grade <= 100)
        {
            ++scores[grade / 10];
        }
    }

    // for (int i = 0; i < 11; ++i)
    // {
    //     scores[i] = i;
    // }

    for (auto i : scores)
        cout << i << " ";

    cout << endl;
    return 0;
}