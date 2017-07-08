#ifndef GUARD_grammar
#define GUARD_grammar
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Ruleset;
typedef std::map<std::string, Ruleset> Grammar;

std::vector<std::string> splitline(const std::string&);
bool bracketed(const std::string&);
Grammar read_grammar(std::istream&);
std::vector<std::string> generate_sentence(const Grammar&);

#endif
