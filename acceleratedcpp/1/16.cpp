// When fed multiple space-separated names,
// this program should print out the first two.
#include <iostream>
#include <string>

int main() {
    std::cout << "What's your name?" << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "."
        << std::endl << "And what is yours?";
    std::cin >> name;
    std::cout << "Hello, " << name
        << "; nice to meet you too!" << std::endl;
    return 0;
}
