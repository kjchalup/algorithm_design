// Split input using a separator and output to 
// a template class output iterator.
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <string>

using std::find_if;
using std::string;

template <class Out>
void split(const string& str, Out os, char sep=' ') {
    typedef string::const_iterator iter;

    iter i = str.begin();
    while(i != str.end()) {
        i = find_if(i, str.end(), [&sep](char c) { return c != sep; });
        iter j = find_if(i, str.end(), [&sep](char c) { return c == sep; });
        if (i != str.end())
           *os++ = string(i, j);
        i = j;
    }
}


int main() {
    string s;
    while (getline(std::cin, s))
        split(s, std::ostream_iterator<string>(std::cout, "\n"), ',');
}
