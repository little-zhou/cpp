#include "andquery.h"

#include <algorithm>
using std::set_intersection;

#include <iterator>
using std::inserter;

QueryResult AndQuery::eval(const TextQuery &text) const
{
    auto left = lhs.eval(text);
    auto right = lhs.eval(text);

    auto ret_lines = shared_ptr<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));

    return QueryResult(rep(), ret_lines, left.get_file());
}