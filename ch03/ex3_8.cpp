#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str("a simple string");
    string::size_type n = 0;
    while (n < str.size())
    {
        // char &temp = str[n];
        // temp = 'X';
        str[n] = 'X';
        ++n;
    }
    cout << str << endl;
    return 0;
}