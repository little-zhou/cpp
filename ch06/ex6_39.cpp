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

int main()
{
    int calc(int, int);
    int calc(const int, const int);
    double calc(int, int);
    return 0;
}