#ifndef GUARD_CHARPIC
#define GUARD_CHARPIC

#include <string>
#include <vector>

typedef std::vector<std::string> picture;
picture frame(const picture&);
picture vcat(const picture&, const picture&);
picture hcat(const picture&, const picture&);
picture center(const picture&);
int display(const picture&);

#endif
