// Index std::cin words by line number.
#include <algorithm>
#include <iostream>
#include <locale>
#include <map>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

using std::cin;         using std::getline;
using std::cout;        using std::find_if;
using std::istream;     using std::isspace;
using std::map;
using std::string;
using std::vector;

typedef map<string, vector<int> > sindex;

// Split a line by whitespace occurrence.
vector<string> splitspace(const string& s)
{
    vector<string> res;
    return boost::split(res, s, boost::is_any_of("\t\n "),
        boost::token_compress_on);
}

sindex xref(istream& in,
    vector<string> findwords(const string&) = splitspace)
{
    sindex table;
    string line;
    int line_num = 0;
    while(getline(in, line)) {
        ++line_num;
        vector<string> words = findwords(line);
        for(vector<string>::const_iterator it = words.begin();
            it != words.end(); ++it)
            table[*it].push_back(line_num);
    }
    return table;
}


int main()
{
    sindex table = xref(cin);

    for (sindex::const_iterator it = table.begin(); it != table.end(); ++it) {
        cout << it->first << " " << it->second[0];
        for (vector<int>::const_iterator strit = it->second.begin() + 1;
            strit != it->second.end(); ++strit) {
            cout << ", " << *strit;
        }
        cout << std::endl;
    }
}
