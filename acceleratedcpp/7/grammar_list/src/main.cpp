#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "grammar.h"

using std::cin;
using std::cout;
using std::list;
using std::string;
using std::vector;

int main() {
    Grammar g = read_grammar(cin);
    list<string> s = generate_sentence(g);
    for (list<string>::const_iterator it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << "\b." << std::endl;
}
