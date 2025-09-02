#ifndef _BINARYQUERY_H
#define _BINARYQUERY_H

#include "query_base.h"
#include "query.h"

class BinaryQuery: public QueryBase
{
protected:
    BinaryQuery(const Query &l, const Query &r, string s): lhs(l), rhs(r), opSym(s){}
    string rep() const 
    {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }

    Query lhs, rhs;
    string opSym;
};

#endif