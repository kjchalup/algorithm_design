// Count bytes in a file (equivalent to wc --chars).

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char **argv) {
    int n_fails = 0;
    unsigned int n_total = 0;

    for (int i = 1; i != argc; ++i) {
        ifstream fin(argv[i]);
        unsigned int n_chars = 0; // TODO: Which type is better?
        char c;

        if (fin) {
            while (fin.get(c))
                n_chars++;
            n_total += n_chars;
            cout << argv[i] << ": " << n_chars << endl;
        }
        else ++n_fails; // File doesn't exist.
    }
    cout << "Total: " << n_total << endl;
    return n_fails;
}
