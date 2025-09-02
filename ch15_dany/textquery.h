#ifndef _TEXTQUERY_H
#define _TEXTQUERY_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <set>
using std::set;

class QueryResult;

class TextQuery
{
public:
    using line_no = vector<string>::size_type;

    TextQuery(ifstream &);

    QueryResult query(const string &) const;

private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm; // word map

    shared_ptr<vector<string>> handlePunct(const string&);
};

#endif