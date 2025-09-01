#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// int main()
// {
//     string line;
//     while (getline(cin, line))
//     {
//         if (!line.empty())
//         {
//             cout << "1" << line << "2" << endl;
//         }
//     }

//     return 0;
// }

// int main()
// {
//     string line;
//     while (getline(cin, line))
//     {
//         cout << "1" << line << "2" << endl;
//     }

//     return 0;
// }

int main()
{
    string line;
    while (cin >> line)
    {
        cout << line << endl;
    }

    return 0;
}
