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
    vector<int> ivec;
    for (int num = 0; cin >> num; ivec.push_back(num));

    auto end = ivec.end();
    for (auto lft = ivec.begin(), rft = ivec.end() - 1; lft <= rft; ++lft, --rft)
    {
        cout << *lft + *rft << " ";
    }
    return 0;
}