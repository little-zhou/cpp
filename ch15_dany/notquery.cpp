#include "notquery.h"
#include "queryresult.h"
#include "query.h"

QueryResult NotQuery::eval(const TextQuery &text) const
{
    auto result = query.eval(text);

    auto ret_lines = make_shared<set<line_no>>();

    auto begin = result.begin();
    auto end = result.end();

    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n)
    {
        if(*begin != n || begin == end)
            ret_lines -> insert(n);
        else if (begin != end)
            ++begin;
    }

    return QueryResult(rep(), ret_lines, result.get_file());
}