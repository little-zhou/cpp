#ifndef _QUERYBASE_H
#define _QUERYBASE_H

#include "queryresult.h"
#include "textquery.h"

#include <string>
using std::string;

class QueryBase
{
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~QueryBase() = default;
private:
    // pure virtual func
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

#endif