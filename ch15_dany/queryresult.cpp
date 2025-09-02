#include "queryresult.h"

#include <iostream>
using std::ostream;

/*
The result of your query fiery is:
        (line 4)like a fiery bird in flight.
        (line 5)A beautiful fiery bird, he tells her,

*/

ostream& print(ostream& os, const QueryResult &qr)
{
    os << "The result of your query " << qr.sought << " is: \n";
    for (const auto &index: *qr.lines){
        os << "\t(line " << index + 1 << ")"
        << *(qr.file->begin() + index) << "\n";
    }
}