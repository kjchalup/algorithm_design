// Split input lines into words.
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::getline;
using std::string;
using std::vector;

typedef string::const_iterator iter;

bool space(char c)
{
    return isspace(c);
}


bool not_space(char c)
{
    return !isspace(c);
}


vector<string> split(const string& line){
    vector<string> ret;
    iter i = line.begin();
    while (i != line.end()) {
        i = find_if(i, line.end(), not_space);
        iter j = find_if(i, line.end(), space);
        if (i != line.end()) 
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}


int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string> words = split(line);
        for(string::size_type i = 0; i != words.size(); ++i)
            cout << words[i] << endl;
    }
    return 0;
}
