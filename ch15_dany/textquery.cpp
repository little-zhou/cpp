#include "textquery.h"
#include "queryresult.h"

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cout;
using std::endl;

TextQuery::TextQuery(ifstream& is): file(new vector<string>)
{
    using std::getline;
    string text;

    // loop file
    while(getline(is, text)){
        // save text to file
        file -> push_back(text);
        // cal index
        int n = (*file).size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto p = handlePunct(word);
            for (auto w: *p){
                auto &lines = wm[w];
                if (!lines)
                    lines.reset(new set<line_no>);
                lines->insert(n);
            }
            // for (auto ele: *p){
            //     cout << ele << " " << endl;
            // }
        }
    }
}

shared_ptr<vector<string>> TextQuery::handlePunct(const string &s)
{
    shared_ptr<vector<string>> p = make_shared<vector<string>>();
    size_t first = 0, index = 0;
    while (index != s.size())
    {
        if (ispunct(s[index])){
            string word = s.substr(first, index - first);
            if (!word.empty())
                p->push_back(word);
            p->push_back(s.substr(index, 1));
            ++index;
            first = index;
        }
        else    
            ++index;
    }
    string trail = s.substr(first);
    if (!trail.empty())
        p->push_back(trail);

    return p;
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end()){
        return QueryResult(sought, nodata, file);
    }else{
        return QueryResult(sought, loc->second, file);
    }
}