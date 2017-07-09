// Grammar-based sentence generation using a stack.
#include <iostream>
#include <list>
#include <random>
#include <stack>
#include <stdexcept>
#include <boost/algorithm/string.hpp>
#include "grammar.h"

using std::getline;
using std::list;
using std::logic_error;
using std::stack;
using std::string;
using std::vector;


vector<string> splitline(const string& line) {
    vector<string> ret;
    boost::split(ret, line, boost::is_any_of(" \t"),
        boost::token_compress_on);
    return ret;
}


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


bool bracketed(const string& s) {
    if (s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>')
        return true;
    else
        return false;
}


int randint(int min, int max) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min,max);
    return uni(rng);
}


list<string> generate_sentence(Grammar& g) {
    list<string> ret;
    stack<string> rulestack({"<sentence>"});
    while (!rulestack.empty()) {
        const string current = rulestack.top();
        rulestack.pop();
        if (!bracketed(current))
            ret.push_back(current);
        else {
            // Pick a ruleset.
            Rule r =  g[current][randint(0, g[current].size() - 1)];
            for (Rule::const_reverse_iterator it = r.rbegin();
                it != r.rend(); ++it)
                rulestack.push(*it);
        }
    }
    return ret;
}
