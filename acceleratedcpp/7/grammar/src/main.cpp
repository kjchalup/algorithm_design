#include <iostream>
#include <string>
#include <vector>
#include "grammar.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main() {
    Grammar g = read_grammar(cin);
    vector<string> s = generate_sentence(g);
    for (vector<string>::const_iterator it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << "." << std::endl;
}
