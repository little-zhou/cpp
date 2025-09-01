#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // string s("Hello World!!!");
    // for (auto &c : s)
    // {
    //     c = toupper(c);
    // }
    // cout << s << endl;
    // return 0;

    // change first alpha to upper
    // string s("some string");
    // if (!s.empty())
    // {
    //     s[0] = toupper(s[0]);
    // }
    // cout << s << endl;

    // change first alpha to upper
    string s("some string");
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
    {
        s[index] = toupper(s[index]);
    }
    cout << s << endl;
    return 0;
}