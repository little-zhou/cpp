#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str;
    string sum;
    while (cin >> str)
    {
        sum += str;
    }
    cout << "Result is " << sum << endl;
    return 0;
}