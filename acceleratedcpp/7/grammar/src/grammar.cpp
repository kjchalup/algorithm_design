// Grammar-based sentence generation using recursion.
#include <iostream>
#include <random>
#include <stdexcept>
#include <boost/algorithm/string.hpp>
#include "grammar.h"

using std::getline;
using std::logic_error;
using std::string;
using std::vector;


// Split a line on whitespace.
vector<string> splitline(const string& line) {
    vector<string> ret;
    boost::split(ret, line, boost::is_any_of(" \t"),
        boost::token_compress_on);
    return ret;
}


// Read grammar from an input stream to a Grammar map.
Grammar read_grammar(std::istream& in) {
    Grammar ret;
    string line;
    while (getline(in, line)) {
        if (!line.empty()) {
            vector<string> words = splitline(line);
            ret[words[0]].push_back(Rule(
                    words.begin() + 1, words.end()));
        }
    }
    return ret;
}


// Check whether a word is surrounded by angular brackets.
bool bracketed(const string& s) {
    if (s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>')
        return true;
    else
        return false;
}


// Generate a random integer in a given range.
int randint(int min, int max) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min,max);
    return uni(rng);
}


// Auxiliary recursive function for generate_sentence.
void generate_aux(const Grammar& g, const string& word, vector<string>& ss) {
    if (!bracketed(word)) {
        ss.push_back(word);
        return;
    } else {
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");
        const Rule& r = it->second[randint(0, it->second.size()-1)];
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            generate_aux(g, *i, ss);
    }
        
}


// Generate a sentence (array of strings) given a grammar.
vector<string> generate_sentence(const Grammar& g) {
    vector<string> ret;
    generate_aux(g, "<sentence>", ret);
    return ret;
}
