#ifndef _NOTQUERY_H
#define _NOTQUERY_H

#include "query_base.h"
#include "query.h"

#include <string>
using std::string;

class QueryResult;
class TextQuery;

class NotQuery: public QueryBase
{
    friend Query operator~(const Query&);
    NotQuery(const Query &q): query(q){}
    string rep() const {return "~(" + query.rep() + ")";}
    QueryResult eval(const TextQuery &) const;

    Query query;
};

inline Query operator~(const Query &oprand)
{
    return shared_ptr<QueryBase>(new NotQuery(oprand));
}

#endif