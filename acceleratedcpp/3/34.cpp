// Report the length of shortest and longest words.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

typedef string::size_type str_sz;
typedef vector<str_sz>::size_type vec_sz;

int main(){
    // Read the input.
    string word;
    vector<str_sz> strlens;
    while(cin >> word)
        strlens.push_back(word.size());
    vec_sz size = strlens.size();

    // Deal with no-input.
    if (size == 0)
        cout << 0;
    else {
        std::sort(strlens.begin(), strlens.end());
        cout << strlens[0] << " " << strlens[size-1];
    }
    return 0;
}



