#include <iostream>
#include <string>
using std::string;

int main()
{
    string s("some string");
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
    {
        *it = toupper(*it);
    }
    std::cout << s << std::endl; 
    return 0;
}