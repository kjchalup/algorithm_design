// Concatenate files given as input args and print them to stdout.
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::string;

int main(int argc, char **argv)
{
    int n_fails = 0;

    for (int i = 1; i != argc; i++) {
        ifstream f_in(argv[i]);
        if (f_in) {
            string s;
            while(getline(f_in, s))
                cout << s << endl;
        } else {
            ++n_fails;
        }
    }

    return n_fails;
}
