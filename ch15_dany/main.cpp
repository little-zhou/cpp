#include "queryresult.h"
#include "textquery.h"
#include "query.h"

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;

// int main()
// {
//     ifstream fin("test.txt");
//     TextQuery text(fin);
//     // auto res = text.query("Daddy");

//     Query q = Query("fiery") & Query("bird") | Query("wind");

//     auto result = q.eval(text);

//     print(cout, result);

//     // print(cout, res) << std::endl;
//     return 0;
// }

// main.cpp
#include "notquery.h"
#include "query.h"

int main()
{
    ifstream fin("test.txt");
    TextQuery text(fin);
    Query q = ~Query("example");
    auto result = q.eval(text);
    print(cout, result);
    return 0;
}
