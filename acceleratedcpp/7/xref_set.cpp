// Index cin words by line number.
// Output sorted by number of occurrences.
// Remove duplicate line occurences.
#include <algorithm>
#include <iostream>
#include <locale>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

using std::cin;         using std::getline;
using std::cout;        using std::find_if;
using std::istream;     using std::isspace;
using std::map;         using std::set;
using std::string;
using std::vector;

typedef map<string, set<int> > sindex;


// Split a string by whitespace.
vector<string> splitspace(const string& s)
{
    vector<string> res;
    return boost::split(res, s, boost::is_any_of(" \t\n"),
        boost::token_compress_on);
}


// Read from cin, keeping a map of which lines each word occurs in.
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
                table[*it].insert(line_num);
    }
    return table;
}


int main()
{
    sindex table = xref(cin);

    // Sort table ids by number of counts.
    // First, get the vector of keys.
    vector<string> keys;
    for (sindex::const_iterator it = table.begin(); it != table.end(); ++it)
        keys.push_back(it->first);

    // Now, sort it by number of lines in the value.
    std::sort(keys.begin(), keys.end(),
        [&table](string& s1, string& s2){
            return table[s1].size() < table[s2].size();
        });

    for (vector<string>::const_iterator it = keys.begin();
        it != keys.end(); ++it) {
        cout << *it << " ";
        for (set<int>::const_iterator strit = table[*it].begin();
            strit != table[*it].end(); ++strit)
            cout << *strit << " ";
        cout << std::endl;
    }
}
