#include <iostream>
#include <vector>
#include <iterator>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::vector;

int main()
{
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp)
    {
        cout << *cp << endl;
        ++cp;
    }

    return 0;
}