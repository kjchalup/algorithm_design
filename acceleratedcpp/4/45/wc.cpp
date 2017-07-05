// Count words.
#include <iostream>
#include <string>
#include <vector>
#include "read.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;

typedef vector<string>::size_type vec_sz;

int main()
{
    // Read words from the input stream.
    vector<string> words;
    read(cin, words);

    // Count words.
    cout << words.size();
    return 0;
}
