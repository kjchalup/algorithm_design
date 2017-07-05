// Manipulations for character pictures.
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include "charpic.h"

using std::string;
using std::vector;

// Compute the size of the longest string in string vector.
string::size_type width(const picture& v)
{
    string::size_type maxlen = 0;
    for (picture::const_iterator it = v.begin();
        it != v.end(); ++it)
        maxlen = std::max(maxlen, (*it).size());
    return maxlen;
}

// Add a rectangular frame to a string vector.
picture frame(const picture& v)
{
    picture ret;
    string::size_type size = width(v);
    string border = string(size + 4, '*');
    ret.push_back(border);
    for (picture::const_iterator it = v.begin(); it != v.end(); ++it)
        ret.push_back("* " + *it + string(size - it->size(), ' ') + " *");
    ret.push_back(border);
    return ret;
}

picture vcat(const picture& top, const picture& btm)
{
    picture ret = top;
    ret.insert(ret.end(), btm.begin(), btm.end());
    return ret;
}

picture hcat(const picture& left, const picture& right)
{
    picture ret;
    string::size_type widthl = width(left) + 1;
    picture::const_iterator itl = left.begin();
    picture::const_iterator itr = right.begin();
    while (itl != left.end() || itr != right.end()) {
        string s;
        if (itl != left.end())
            s = *itl++;
        s += string(widthl - s.size(), ' ');
        if (itr != right.end())
            s += *itr++;
        ret.push_back(s);
    }
    return ret;
}

picture center(const picture& pic)
{
    picture ret;
    string::size_type size = width(pic);
    for (picture::const_iterator it = pic.begin(); it != pic.end(); ++it)
        ret.push_back(string((size - it->size()) / 2, ' ') + *it);
    return ret;
}

int display(const picture& pic)
{
    for (picture::const_iterator it = pic.begin(); it !=  pic.end(); ++it)
        std::cout << *it << std::endl;;
    return 0;
}

