#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cstring>
#include <typeinfo>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;

string (&func(int i))[10];

//
typedef string st[10];
// using st = string[10];
st&   func2(int i);

auto func3(int i) -> string (&)[10];

int main()
{

    return 0;
}