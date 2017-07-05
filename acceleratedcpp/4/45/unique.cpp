// Count unique words.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "read.h"

using std::cin;
using std::cout;
using std::sort;
using std::string;
using std::vector;

typedef vector<string>::size_type vec_sz;

int main()
{
    // Read words from the input stream.
    vector<string> words;
    read(cin, words);

    // Count unique words.
    sort(words.begin(), words.end());
    vec_sz n_unique = 0;
    string word = "";
    for (vec_sz word_id = 0; word_id < words.size(); ++word_id)
        if (words[word_id] != word) {
            ++n_unique;
            word = words[word_id];
        }
    cout << n_unique;
    return 0;
}
