// Use output generators to output grammar sampling results.
#include <algorithm>
#include <iostream>
#include <iterator>
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
    list<string> out;
    std::ostream_iterator<string> out2(cout, " ");

    generate_sentence(g, std::back_inserter(out));
    std::copy(out.begin(), out.end(), out2);
    
    cout << std::endl;
    generate_sentence(g, out2);
}
