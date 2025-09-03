#include "orquery.h"

QueryResult OrQuery::eval(const TextQuery &text) const 
{
    auto left = lhs.eval(text);
    auto right = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());\
    ret_lines -> insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}