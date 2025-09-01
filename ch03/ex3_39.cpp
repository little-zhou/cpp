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
    // string s1("abc");
    // string s2("abc");

    // if (s1 == s2)
    //     cout << "Two string equal." << endl;
    // else
    //     cout << "Two string not equal." << endl;

    const char *str1 = "hello";
    const char *str2 = "hello";

    if (strcmp(str1, str2) == 0)
        cout << "Two string equal." << endl;
    else
        cout << "Two string not equal." << endl;

    return 0;
}