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
    vector<string> text;
    for (string line; getline(cin, line); text.push_back(line))
        ;

    for (auto &word : text)
    {
        for (auto &ch : word)
        {
            if (isalpha(ch))
                ch = toupper(ch);
        }
        cout << word << " ";
    }

    return 0;
}