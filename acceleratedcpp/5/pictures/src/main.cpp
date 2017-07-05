#include <iostream>
#include <string>
#include "charpic.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

// Read a picture from a file, frame it, and put
// the framed version side-by-side the original.
int main(){
    string line;
    picture pic;
    while (getline(cin, line))
        pic.push_back(line);

    cout << "Original: " << endl;;
    display(pic);
    cout << endl << endl;

    cout << "Framed: " << endl;
    display(frame(pic));
    cout << endl << endl;

    cout << "hcat: " << endl;
    display(hcat(pic, frame(pic)));
    cout << endl << endl;

    cout << "vcat: " << endl;
    display(vcat(pic, frame(pic)));
    cout << endl << endl;

    cout << "centered: " << endl;
    display(center(pic));
    cout << endl << endl;
}


