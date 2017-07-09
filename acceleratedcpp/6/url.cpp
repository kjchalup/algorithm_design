// Extract all urls from the input stream.
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using std::string;
using std::vector;

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


int main()
{
    string line;
    vector<string> urls;
    while(std::getline(std::cin, line)){
        urls = find_urls(line);
        for(vector<string>::const_iterator it = urls.begin();
            it != urls.end(); ++it)
            std::cout << *it << std::endl;
    }
    return 0;
}
