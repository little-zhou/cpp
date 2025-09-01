#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str("a simple string");
    for (auto &s : str)
    {
        s = 'X';
    }
    cout << str << endl;
    return 0;
}