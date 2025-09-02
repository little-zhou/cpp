#include "queryresult.h"
#include "textquery.h"

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;

int main()
{
    ifstream fin("test.txt");
    TextQuery text(fin);
    auto res = text.query("Daddy");
    print(cout, res) << std::endl;
    return 0;
}