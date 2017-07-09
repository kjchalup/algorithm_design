// Index cin urls by line number.
// Output sorted by number of occurrences.
// Remove duplicate line numbers.
#include <algorithm>
#include <cctype>
#include <iostream>
#include <locale>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

#include <algorithm>
using std::cin;         using std::getline;
using std::cout;        using std::find_if;
using std::istream;     using std::isspace;
using std::map;         using std::set;
using std::string;
using std::vector;

typedef map<string, set<int> > sindex;
typedef string::const_iterator citer;

bool not_url_char(char c)
{
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    return !(isalnum(c) ||
        find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}


citer url_end(citer b, citer e){
    return find_if(b, e, not_url_char);
}


citer url_beg(citer b, citer e)
{
    static const string sep = "://";
    citer i = b;
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        if (i != b && i + sep.size() != e) {
            citer beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        i += sep.size();
    }
    return e;
}


vector<string> find_urls(const string& s)
{
    vector<string> ret;
    citer b = s.begin();
    citer e = s.end();

    while((b = url_beg(b, e)) != e){
        citer last = url_end(b, e);
        ret.push_back(string(b, last));
        b = last;
    }

    return ret;
}


// Read from cin, keeping a map of which lines each word occurs in.
sindex xref(istream& in,
    vector<string> findwords(const string&) = find_urls)
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
