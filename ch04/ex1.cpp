#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cstring>
#include <typeinfo>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int a = 10;
    cout << typeid(decltype(a)).name() << endl;
    return 0;
}