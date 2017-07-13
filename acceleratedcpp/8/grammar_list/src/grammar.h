#ifndef GUARD_grammar
#define GUARD_grammar
#include <list>
#include <map>
#include <stack>
#include <string>
#include <vector>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Ruleset;
typedef std::map<std::string, Ruleset> Grammar;

std::vector<std::string> splitline(const std::string&);
bool bracketed(const std::string&);
Grammar read_grammar(std::istream&);
int randint(int, int);

template <class OutputIterator>
void generate_sentence(Grammar& g, OutputIterator out) {
    std::stack<std::string> rulestack({"<sentence>"});
    while (!rulestack.empty()) {
        const std::string current = rulestack.top();
        rulestack.pop();
        if (!bracketed(current))
            *out++ = current;
        else {
            // Pick a ruleset.
            Rule r =  g[current][randint(0, g[current].size() - 1)];
            for (Rule::const_reverse_iterator it = r.rbegin();
                it != r.rend(); ++it)
                rulestack.push(*it);
        }
    }
}
#endif
