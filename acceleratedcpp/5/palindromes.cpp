// Find all the palindromes in a file, as well as the longest one.
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

typedef string::size_type str_sz;

// Check whether a word is a palindrome.
bool is_palindrome(const string& word)
{
    str_sz len = word.size();
    for (str_sz i = 0; i < len; ++i)
        if (word[i] != word[len - i - 1])
            return false;
    return true;
}

// Check whether a word has any descenders or ascenders.
bool has_ders(const string& word)
{
    for (string::const_iterator l = word.begin(); l != word.end(); ++l)
        if (*l == 'b' || *l == 'd' || *l == 'f' || *l == 'h' ||
            *l == 'k' || *l == 'l' || *l == 't' || *l == 'g' ||
            *l == 'j' || *l == 'p' || *l == 'q' || *l == 'y')
            return false;
    return true;
}

int main()
{
    string word;
    str_sz longest_len = 0;
    string longest_word;
    while (cin >> word) {
        if (is_palindrome(word)){
            cout << word << endl;
            if (word.size() > longest_len){
                longest_len = word.size();
                longest_word = word;
            }
        }
    }
    cout << longest_word << endl;
    return 0;
}

