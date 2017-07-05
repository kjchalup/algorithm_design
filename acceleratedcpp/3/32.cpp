// Count unique words.
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;             using std::sort;
using std::cout;            using std::streamsize;
using std::endl;            using std::string;
using std::setprecision;    using std::vector;

typedef vector<string>::size_type vec_sz;

int main()
{
    string word;
    vector<string> words;
    while(cin >> word)
        words.push_back(word);
    vec_sz size = words.size();
    if (size == 0){
        cout << 0;
        return 0;
    }

    // Sort.
    sort(words.begin(), words.end());

    // Count unique.
    vec_sz unique = 0;
    string previous = "";
    for (vec_sz word_id = 0; word_id != size; word_id++){
        if (words[word_id] != previous)
            unique++;
        previous = words[word_id];
    }
    cout << unique;
    return 0;
}

