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

int main()
{
    int temp = 0;
    while (cin >> temp && temp != 42)
    {
        cout << temp << endl;
    }

    cout << "End input " << temp << endl;
    return 0;
}