// A minimalistic low-level implementation of a single-linked list of strings.
#include <cstddef>
#include <iostream>

using std::size_t;

class Stringlist {
    public:
        Stringlist(): head(0), size(0) { };
        append(char *str) {

    private:
        char **data;

        size_t size;
};
        
int main()
{
    Stringlist l();
    l.append("Ha");
    l.append("Ba");
    l.append("Ka");
    // Should print 1\n0\n.
    std::cout << l.find("Ka") << std::endl;
    std::cout << l.find("La") << std::endl;
}

