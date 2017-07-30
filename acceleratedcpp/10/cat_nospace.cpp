// Concatenate files given as input args and print them to stdout.
// Use streams.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>

using std::copy;
using std::cout;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::string;

int main(int argc, char **argv)
{
    int n_fails = 0;

    for (int i = 1; i != argc; i++) {
        ifstream fin(argv[i]);
        if (fin)
            copy(istream_iterator<string> (fin), istream_iterator<string> (),
                ostream_iterator<string> (cout, ""));
        else ++n_fails;
    }

    return n_fails;
}
