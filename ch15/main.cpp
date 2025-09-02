#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

// #include "queryhistory.h"
#include "queryresult.h"
#include "textquery.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"
#include "notquery.h"

int main()
{
    ifstream fin("test.txt");
    TextQuery text(fin);
    // QueryHistory history;
    // history.add_query(q0);
    // history.add_query(q1);
    // history[0] = history[0] | q2;

    // auto result = history[0].eval(text);
    // auto q = ~Query("Alice");
    // Query q = Query("fiery") & Query("bird") | Query("wind");

    Query q = Query("dany");

    auto result = q.eval(text);

    print(cout, result);

    return 0;
}