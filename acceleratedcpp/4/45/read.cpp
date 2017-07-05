// Read words from an input stream into a vector.
#include "read.h"

using std::istream;
using std::string;
using std::vector;

istream& read(istream& is, vector<string>& words)
{
    string word;
    is.clear();
    while(is >> word)
        words.push_back(word);
    is.clear();
    return is;
}

