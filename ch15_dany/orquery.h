#ifndef _ORQUERY_H
#define _ORQUERY_H

#include "binaryquery.h"

class QueryResult;
class TextQuery;

class OrQuery: public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right): BinaryQuery(left, right, "|"){}
    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

#endif