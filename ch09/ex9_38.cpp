#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> v;
    for (string buffer; cin >> buffer; v.push_back(buffer))
        cout << v.capacity() << std::endl;

    return 0;
}